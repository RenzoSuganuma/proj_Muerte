// Copyright (c) 2025, DiscoveryGameWorks All Rights Reserved.


#include "MuerteGameModeBase.h"

void AMuerteGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	if (UMuerteGameInstance* Instance = Cast<UMuerteGameInstance>(GetGameInstance()))
	{
		m_gameInstance = Instance;
	}
}

void AMuerteGameModeBase::Destroyed()
{
	Super::Destroyed();
}
