// Copyright (c) 2025, DiscoveryGameWorks All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "MuerteGameInstance.h"
#include "GameFramework/GameModeBase.h"
#include "MuerteGameModeBase.generated.h"

// Muerteゲームモード基底クラス
UCLASS()
class PROJ_MUERTE_API AMuerteGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

private:
	TObjectPtr<UMuerteGameInstance> m_gameInstance;

	// 関数シグネチャ
	virtual void BeginPlay() override;
	virtual void Destroyed() override;
};
