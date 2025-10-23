// Copyright (c) 2025, DiscoveryGameWorks All Rights Reserved.


#include "MuertePlayerControllerBase.h"
#include "MuerteGameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Engine/Engine.h"
#include "GameFramework/PawnMovementComponent.h"

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
	auto input = value.Get<FVector2D>().GetSafeNormal();
	double deltaTime = UGameplayStatics::GetWorldDeltaSeconds(this);
	auto player = UGameplayStatics::GetPlayerPawn(this, 0);
	if (!player) return;

	if (input.X == 0.0f || input.Y == 0.0f)
	{
		auto vel = player->GetMovementComponent()->Velocity;
		if (vel.X != 0.0f || vel.Y != 0.0f)
		{
			player->GetMovementComponent()->StopMovementImmediately();
		}
	}

	auto f = player->GetActorForwardVector();
	auto r = player->GetActorRightVector();
	f *= input.Y;
	r *= input.X;

	player->AddMovementInput(f);
	player->AddMovementInput(r);
}

void AMuertePlayerControllerBase::OnLook(const FInputActionValue& value)
{
	auto input = value.Get<FVector2D>();
	double deltaTime = UGameplayStatics::GetWorldDeltaSeconds(this);
	auto player = UGameplayStatics::GetPlayerPawn(this, 0);
	player->AddControllerYawInput(deltaTime * input.X * (m_gi ? 1.0f : m_gi->GetMouseSensitivity().X));

	// ここでカメラの回転を実行、実際にプレイヤーキャラにはPitch回転のみ適応する
	ControlRotation.Add(
		deltaTime * input.Y * (m_gi ? 1.0f : m_gi->GetMouseSensitivity().Y) * (m_gi->GetMouseInverseY() ? -1.0f : 1.0f),
		0.0f,
		0.0f);
}
