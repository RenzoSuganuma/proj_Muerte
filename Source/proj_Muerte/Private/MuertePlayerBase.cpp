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

	// 入力のセットアップ
	if (UMuerteGameInstance* instance = Cast<UMuerteGameInstance>(GetGameInstance()))
	{
		if (TObjectPtr<UEnhancedInputComponent> input = instance->GetPlayerController()->GetInputComponent())
		{
			input->BindAction(
				m_inputActionMove, ETriggerEvent::Triggered, this,
				&AMuertePlayerBase::ActionMove);

			input->BindAction(
				m_inputActionMove, ETriggerEvent::Completed, this,
				&AMuertePlayerBase::OnMoveCanceled);
			input->BindAction(
				m_inputActionMove, ETriggerEvent::Canceled, this,
				&AMuertePlayerBase::OnMoveCanceled);
		}
	}
}

// Called every frame
void AMuertePlayerBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto arrow = GetArrowComponent();
	auto move = GetCharacterMovement();
	if (move and arrow)
	{
		auto forwardV = arrow->GetForwardVector() * m_input.Y;
		auto rightV = arrow->GetRightVector() * m_input.X;
		auto inputRaw = (forwardV + rightV);
		inputRaw.Normalize();
		move->AddInputVector(inputRaw);
	}
}

// Called to bind functionality to input
void AMuertePlayerBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void AMuertePlayerBase::ActionMove(const FInputActionValue& in_actionValue)
{
	m_input = in_actionValue.Get<FVector2D>();
}

void AMuertePlayerBase::OnMoveCanceled(const FInputActionValue& in_actionValue)
{
	m_input = FVector2D::ZeroVector;
}
