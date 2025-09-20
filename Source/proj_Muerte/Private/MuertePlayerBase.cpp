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
			// Move
			input->BindAction(
				m_inputActionMove, ETriggerEvent::Triggered, this,
				&AMuertePlayerBase::OnActionMove);
			input->BindAction(
				m_inputActionMove, ETriggerEvent::Completed, this,
				&AMuertePlayerBase::OnMoveCanceled);
			input->BindAction(
				m_inputActionMove, ETriggerEvent::Canceled, this,
				&AMuertePlayerBase::OnMoveCanceled);
			// Look
			input->BindAction(
				m_inputActionLook, ETriggerEvent::Triggered, this,
				&AMuertePlayerBase::OnActionLook);
			input->BindAction(
				m_inputActionLook, ETriggerEvent::Completed, this,
				&AMuertePlayerBase::OnActionLook);
			input->BindAction(
				m_inputActionLook, ETriggerEvent::Canceled, this,
				&AMuertePlayerBase::OnActionLook);
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
		auto forwardV = arrow->GetForwardVector() * m_inputMove.Y;
		auto rightV = arrow->GetRightVector() * m_inputMove.X;
		auto inputRaw = (forwardV + rightV);
		inputRaw.Normalize();
		move->AddInputVector(inputRaw);
	}

	// Y-Axis Look
	auto trans = GetActorTransform();
	auto rotator = trans.Rotator().Add(0, m_inputLook.X * 100.0f, 0);
	trans.SetRotation(rotator.Quaternion());
	SetActorTransform(trans);
}

// Called to bind functionality to input
void AMuertePlayerBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void AMuertePlayerBase::OnActionMove(const FInputActionValue& in_actionValue)
{
	m_inputMove = in_actionValue.Get<FVector2D>();
}

void AMuertePlayerBase::OnMoveCanceled(const FInputActionValue& in_actionValue)
{
	m_inputMove = FVector2D::ZeroVector;
}

void AMuertePlayerBase::OnActionLook(const FInputActionValue& in_actionValue)
{
	m_inputLook = in_actionValue.Get<FVector2D>();

	UKismetSystemLibrary::PrintString(this, m_inputLook.ToString());
}

void AMuertePlayerBase::OnLookCanceled(const FInputActionValue& in_actionValue)
{
	m_inputLook = FVector2D::ZeroVector;
}
