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
		input->BindAction(m_iActionMove, ETriggerEvent::Completed, this,
		                  &AMuertePlayerControllerBase::OnMoveCanceled);
		input->BindAction(m_iActionMove, ETriggerEvent::Canceled, this,
		                  &AMuertePlayerControllerBase::OnMoveCanceled);
		// マウス視点操作
		input->BindAction(m_iActionMouseLook, ETriggerEvent::Triggered, this,
		                  &AMuertePlayerControllerBase::OnLook);
		input->BindAction(m_iActionMouseLook, ETriggerEvent::Completed, this,
		                  &AMuertePlayerControllerBase::OnLookCanceled);
		input->BindAction(m_iActionMouseLook, ETriggerEvent::Canceled, this,
		                  &AMuertePlayerControllerBase::OnLookCanceled);
	}

	if (TObjectPtr<UMuerteGameInstance> i = Cast<UMuerteGameInstance>(GetGameInstance()))
	{
		m_game = i;
	}
}

void AMuertePlayerControllerBase::Destroyed()
{
	Super::Destroyed();

	DisableInput(this);
	auto inputSystem = GetLocalPlayer()->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();
	inputSystem->ClearAllMappings();

	m_game = nullptr;
}

void AMuertePlayerControllerBase::OnMove(const FInputActionValue& value)
{
	auto input = value.Get<FVector2D>();
	m_game->GetPlayerActor()->AddMovementInput(m_game->GetPlayerActor()->GetActorLocation().ForwardVector * input.Y);
	m_game->GetPlayerActor()->AddMovementInput(m_game->GetPlayerActor()->GetActorLocation().RightVector * input.X);
}

void AMuertePlayerControllerBase::OnMoveCanceled(const FInputActionValue& value)
{
	m_game->GetPlayerActor()->AddMovementInput(m_game->GetPlayerActor()->GetActorLocation().ForwardVector * 0.f);
	m_game->GetPlayerActor()->AddMovementInput(m_game->GetPlayerActor()->GetActorLocation().RightVector * 0.f);
}

void AMuertePlayerControllerBase::OnLook(const FInputActionValue& value)
{
	auto input = value.Get<FVector2D>();
	m_game->GetPlayerActor()->GetActorTransform().Rotator().Add(0.f, input.X, 0.f);
}

void AMuertePlayerControllerBase::OnLookCanceled(const FInputActionValue& value)
{
	auto input = value.Get<FVector2D>();
	m_game->GetPlayerActor()->GetActorTransform().Rotator().Add(0.f, 0.f, 0.f);
}
