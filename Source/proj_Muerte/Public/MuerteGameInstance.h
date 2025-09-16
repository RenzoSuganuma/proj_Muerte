// Copyright (c) 2025, DiscoveryGameWorks All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MuertePlayerControllerBase.h"
#include "MuerteGameInstance.generated.h"

// Muerteゲームインスタンスのクラス
UCLASS()
class PROJ_MUERTE_API UMuerteGameInstance : public UGameInstance
{
	GENERATED_BODY()

	// 
	friend class AMuertePlayerControllerBase; // ←サービスロケーター的な使い方をしたいのでこのような書き方

private:
	TObjectPtr<AMuertePlayerControllerBase> m_playerController;

public:
	// MuertePlayerControllerを返す
	TObjectPtr<AMuertePlayerControllerBase> GetPlayerController();
};
