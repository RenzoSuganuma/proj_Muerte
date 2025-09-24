// Copyright (c) 2025, DiscoveryGameWorks All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MuertePlayerBase.h"
#include "MuerteGameInstance.generated.h"

// Muerteゲームインスタンスのクラス
UCLASS()
class PROJ_MUERTE_API UMuerteGameInstance : public UGameInstance
{
	GENERATED_BODY()

	friend class AMuertePlayerBase;

private:
	TObjectPtr<AMuertePlayerBase> m_playerActor;

public:
	TObjectPtr<AMuertePlayerBase> GetPlayerActor();
};
