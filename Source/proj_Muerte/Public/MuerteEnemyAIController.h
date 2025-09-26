// Copyright (c) 2025, DiscoveryGameWorks All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "MuerteEnemyAIController.generated.h"

/**
 * 
 */
UCLASS()
class PROJ_MUERTE_API AMuerteEnemyAIController : public AAIController
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	TObjectPtr<UBehaviorTree> m_behaviourTree;

	virtual void BeginPlay() override;
};
