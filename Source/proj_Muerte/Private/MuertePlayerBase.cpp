// Copyright (c) 2025, DiscoveryGameWorks All Rights Reserved.


#include "MuertePlayerBase.h"
#include "MuerteGameInstance.h"
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
		if (IsValid(camera))
		{
			m_cameraComponent = camera;
		}
	}
	// FOV設定
	if (IsValid(m_cameraComponent))
	{
		m_cameraComponent->SetFieldOfView(m_fovDefault);
	}

	// 入力のセットアップ
	if (UMuerteGameInstance* instance = Cast<UMuerteGameInstance>(GetGameInstance()))
	{
		instance->GetPlayerController()->GetInputComponent()->BindAction(
			m_inputActionMove, ETriggerEvent::Triggered, this,
			&AMuertePlayerBase::ActionMove);
	}
}

// Called every frame
void AMuertePlayerBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AMuertePlayerBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void AMuertePlayerBase::ActionMove(const FInputActionValue& in_actionValue)
{
	auto moveVec = in_actionValue.Get<FVector2D>();
	UKismetSystemLibrary::PrintString(this, moveVec.ToString());
}
