// Copyright (c) 2025, DiscoveryGameWorks All Rights Reserved.


#include "MuertePlayerControllerBase.h"
#include "MuerteGameInstance.h"
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
		m_inputComponent = component;
	}

	if (UEnhancedInputLocalPlayerSubsystem* inputSystem = GetLocalPlayer()->GetSubsystem<
		UEnhancedInputLocalPlayerSubsystem>())
	{
		inputSystem->ClearAllMappings();
		if (m_defaultMappingContext)
			inputSystem->AddMappingContext(m_defaultMappingContext, 0);
		if (m_mouseLookMappingContext)
			inputSystem->AddMappingContext(m_mouseLookMappingContext, 0);
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

TObjectPtr<UEnhancedInputComponent> AMuertePlayerControllerBase::GetInputComponent()
{
	return m_inputComponent;
}
