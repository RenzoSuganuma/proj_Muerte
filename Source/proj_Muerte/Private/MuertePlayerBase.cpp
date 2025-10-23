// Copyright (c) 2025, DiscoveryGameWorks All Rights Reserved.


#include "MuertePlayerBase.h"
#include "MuerteGameInstance.h"
#include "Components/ArrowComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetSystemLibrary.h"

// Sets default values
AMuertePlayerBase::AMuertePlayerBase()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	// 移動パラメータを調整して滑りを軽減
	if (UCharacterMovementComponent* MovementComp = GetCharacterMovement())
	{
		// 摩擦を増加させて滑りを軽減
		MovementComp->BrakingFrictionFactor = 2.0f;
		MovementComp->GroundFriction = 8.0f;
		
		// 減速を早くしてよりレスポンシブに
		MovementComp->BrakingDecelerationWalking = 2048.0f;
		MovementComp->BrakingDecelerationFalling = 0.0f;
		
		// 最大速度を適切に設定
		MovementComp->MaxWalkSpeed = 600.0f;
		MovementComp->MaxAcceleration = 2048.0f;
		
		// 空中での制御を改善
		MovementComp->AirControl = 0.35f;
		MovementComp->AirControlBoostMultiplier = 0.0f;
		MovementComp->AirControlBoostVelocityThreshold = 0.0f;
	}
}

// Called when the game starts or when spawned
void AMuertePlayerBase::BeginPlay()
{
	Super::BeginPlay();

	// カメラコンポーネントを取得
	TArray<USceneComponent*> components;
	GetRootComponent()->GetChildrenComponents(true, components);
	for (auto c : components)
	{
		UCameraComponent* camera = Cast<UCameraComponent>(c);
		if (camera)
		{
			m_cameraComponent = camera;
		}
	}

	// FOV設定
	if (m_cameraComponent)
	{
		m_cameraComponent->SetFieldOfView(m_fovDefault);
	}
	
	// 移動パラメータを設定
	SetMovementParameters();
}

// Called every frame
void AMuertePlayerBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	// 滑り防止処理を適用
	ApplyAntiSlideMovement();
}

// Called to bind functionality to input
void AMuertePlayerBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void AMuertePlayerBase::Destroyed()
{
	Super::Destroyed();
}

void AMuertePlayerBase::SetMovementParameters()
{
	if (UCharacterMovementComponent* MovementComp = GetCharacterMovement())
	{
		// より厳密な移動制御のためのパラメータ設定
		MovementComp->BrakingFrictionFactor = 3.0f;
		MovementComp->GroundFriction = 10.0f;
		MovementComp->BrakingDecelerationWalking = 4096.0f;
		MovementComp->MaxWalkSpeed = 600.0f;
		MovementComp->MaxAcceleration = 2048.0f;
		
		// 滑りを防ぐための追加設定
		MovementComp->bUseSeparateBrakingFriction = true;
		MovementComp->BrakingFriction = 2.0f;
	}
}

void AMuertePlayerBase::ApplyAntiSlideMovement()
{
	if (UCharacterMovementComponent* MovementComp = GetCharacterMovement())
	{
		// 現在の速度を取得
		FVector CurrentVelocity = GetVelocity();
		
		// 入力がない場合、より積極的に減速
		if (GetLastMovementInputVector().IsNearlyZero())
		{
			// 地面にいる場合のみ適用
			if (MovementComp->IsMovingOnGround())
			{
				// より強い減速を適用
				FVector AntiSlideForce = -CurrentVelocity * 0.5f;
				MovementComp->AddForce(AntiSlideForce);
			}
		}
	}
}
