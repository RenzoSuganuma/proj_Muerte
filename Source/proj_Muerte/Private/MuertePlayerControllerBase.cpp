// Copyright (c) 2025, DiscoveryGameWorks All Rights Reserved.


#include "MuertePlayerControllerBase.h"
#include "MuerteGameInstance.h"
#include "EnhancedInputComponent.h"
#include "Kismet/KismetSystemLibrary.h"

void AMuertePlayerControllerBase::BeginPlay()
{
	Super::BeginPlay();

	if (UMuerteGameInstance* instance = Cast<UMuerteGameInstance>(GetGameInstance()))
	{
		instance->m_playerController = this;
	}

	if (UEnhancedInputComponent* component = CastChecked<UEnhancedInputComponent>(InputComponent))
	{
		component->BindAction(m_inputActionMove, ETriggerEvent::Triggered, this,
		                      &AMuertePlayerControllerBase::ActionMove);
	}

	if (UEnhancedInputLocalPlayerSubsystem* inputSystem = GetLocalPlayer()->GetSubsystem<
		UEnhancedInputLocalPlayerSubsystem>())
	{
		inputSystem->ClearAllMappings();
		inputSystem->AddMappingContext(m_mappingContext, 0);
	}
}

void AMuertePlayerControllerBase::Destroyed()
{
	Super::Destroyed();

	if (UMuerteGameInstance* instance = Cast<UMuerteGameInstance>(GetGameInstance()))
	{
		instance->m_playerController = nullptr;
	}
}

void AMuertePlayerControllerBase::ActionMove(const FInputActionValue& in_actionValue)
{
	auto moveVec = in_actionValue.Get<FVector2D>();
	UKismetSystemLibrary::PrintString(this, moveVec.ToString());
}
