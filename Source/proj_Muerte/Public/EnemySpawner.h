// Copyright (c) 2025, DiscoveryGameWorks All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EMuerteGameStatusEnum.h"
#include "MuerteEnemyBase.h"
#include "MuerteGameInstance.h"
#include "GameFramework/Actor.h"
#include "EnemySpawner.generated.h"

UCLASS()
class PROJ_MUERTE_API AEnemySpawner : public AActor
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	TSubclassOf<AMuerteEnemyBase> m_enemyOriginal;

	TObjectPtr<AMuerteEnemyBase> m_enemy;
	TObjectPtr<UMuerteGameInstance> m_instance;

	virtual void BeginPlay() override;
	virtual void Destroyed() override;

public:
	UFUNCTION(BlueprintCallable)
	void OnInGameStatusChanged(EMuerteGameStatusEnum stat);
};
