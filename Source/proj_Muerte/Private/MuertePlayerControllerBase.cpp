// Copyright (c) 2025, DiscoveryGameWorks All Rights Reserved.


#include "MuertePlayerControllerBase.h"
#include "MuerteGameInstance.h"
#include "Kismet/KismetSystemLibrary.h"

void AMuertePlayerControllerBase::BeginPlay()
{
	Super::BeginPlay();

	EnableInput(this);

	// マッピングを追加
	auto inputSystem = GetLocalPlayer()->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();
	inputSystem->ClearAllMappings();
	inputSystem->AddMappingContext(m_mapDefault, 0);
	inputSystem->AddMappingContext(m_mapMouseLook, 0);

	// アクションをバインド
	if (TObjectPtr<UEnhancedInputComponent> input = CastChecked<UEnhancedInputComponent>(InputComponent))
	{
		// 移動
		input->BindAction(m_iActionMove, ETriggerEvent::Triggered, this,
		                  &AMuertePlayerControllerBase::OnMove);
		// マウス視点操作
		input->BindAction(m_iActionMouseLook, ETriggerEvent::Triggered, this,
		                  &AMuertePlayerControllerBase::OnLook);
	}

	if (TObjectPtr<UMuerteGameInstance> i = Cast<UMuerteGameInstance>(GetGameInstance()))
	{
		m_gi = i;
	}
}

void AMuertePlayerControllerBase::Destroyed()
{
	Super::Destroyed();

	DisableInput(this);
	auto inputSystem = GetLocalPlayer()->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();
	inputSystem->ClearAllMappings();

	m_gi = nullptr;
}

void AMuertePlayerControllerBase::OnMove(const FInputActionValue& value)
{
	auto input = value.Get<FVector2D>();
	m_gi->GetPlayerActor()->AddMovementInput(
		m_gi->GetPlayerActor()->GetActorForwardVector() * input.Y);
	m_gi->GetPlayerActor()->AddMovementInput(
		m_gi->GetPlayerActor()->GetActorRightVector() * input.X);
}

void AMuertePlayerControllerBase::OnLook(const FInputActionValue& value)
{
	auto input = value.Get<FVector2D>();
	ControlRotation.Add(0.f,
	                    input.X * (m_gi ? 1.f : m_gi->GetMouseSensitivity()),
	                    0.f);
}
