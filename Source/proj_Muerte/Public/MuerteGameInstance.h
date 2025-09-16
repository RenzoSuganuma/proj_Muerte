// Copyright (c) 2025, DiscoveryGameWorks All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MuertePlayerControllerBase.h"
#include "MuerteGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class PROJ_MUERTE_API UMuerteGameInstance : public UGameInstance
{
	GENERATED_BODY()

	friend class AMuertePlayerControllerBase;

private:
	TObjectPtr<AMuertePlayerControllerBase> m_playerController;

public:
	TObjectPtr<AMuertePlayerControllerBase> GetPlayerController();
};
