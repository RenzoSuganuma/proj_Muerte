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

	UPROPERTY(EditAnywhere)
	TObjectPtr<UInputAction> m_inputActionMove;

private:
	void BeginPlay() override;

public:
	void ActionMove(const FInputActionValue& in_actionValue);
};
