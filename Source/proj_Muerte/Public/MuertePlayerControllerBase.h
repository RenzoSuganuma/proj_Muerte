// Copyright (c) 2025, DiscoveryGameWorks All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputAction.h"
#include "InputMappingContext.h"
#include "InputActionValue.h"
#include "MuerteGameInstance.h"
#include "MuertePlayerControllerBase.generated.h"

// プレイヤーコントローラーの基底クラス
UCLASS()
class PROJ_MUERTE_API AMuertePlayerControllerBase : public APlayerController
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	TObjectPtr<UInputMappingContext> m_mapDefault;

	UPROPERTY(EditAnywhere)
	TObjectPtr<UInputMappingContext> m_mapMouseLook;

	UPROPERTY(EditAnywhere)
	TObjectPtr<UInputAction> m_iActionMove;

	UPROPERTY(EditAnywhere)
	TObjectPtr<UInputAction> m_iActionMouseLook;

private:
	TObjectPtr<UMuerteGameInstance> m_gi;
	
	virtual void BeginPlay() override;
	virtual void Destroyed() override;

	void OnMove(const FInputActionValue& value);
	void OnLook(const FInputActionValue& value);
};
