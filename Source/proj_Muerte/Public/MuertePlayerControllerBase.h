// Copyright (c) 2025, DiscoveryGameWorks All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "MuertePlayerControllerBase.generated.h"

/**
 * 
 */
UCLASS()
class PROJ_MUERTE_API AMuertePlayerControllerBase : public APlayerController
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	TObjectPtr<UInputMappingContext> m_mappingContext;

private:
	TObjectPtr<UEnhancedInputComponent> m_inputComponent;
	
	virtual void BeginPlay() override;
	virtual void Destroyed() override;

public:
	TObjectPtr<UEnhancedInputComponent> GetInputComponent();
};
