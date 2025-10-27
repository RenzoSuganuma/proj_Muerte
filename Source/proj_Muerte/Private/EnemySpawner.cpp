// Copyright (c) 2025, DiscoveryGameWorks All Rights Reserved.


#include "EnemySpawner.h"

void AEnemySpawner::BeginPlay()
{
	Super::BeginPlay();

	if (UMuerteGameInstance* instance = Cast<UMuerteGameInstance>(GetGameInstance()))
	{
		m_instance = instance;
		m_instance->OnGameStatusChanged.AddDynamic(this, &AEnemySpawner::OnInGameStatusChanged);
	}
}

void AEnemySpawner::Destroyed()
{
	m_instance->OnGameStatusChanged.RemoveDynamic(this, &AEnemySpawner::OnInGameStatusChanged);

	Super::Destroyed();
}

void AEnemySpawner::OnInGameStatusChanged(EMuerteGameStatusEnum stat)
{
	if (stat == EMuerteGameStatusEnum::InGame)
	{
		if (AMuerteEnemyBase* result = Cast<AMuerteEnemyBase>(GetWorld()->SpawnActor(m_enemyOriginal)))
		{
			m_enemy = result;
			m_enemy->SetActorLocation(GetActorLocation());
		}
	}
}
