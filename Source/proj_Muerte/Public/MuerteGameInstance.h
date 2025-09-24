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

private:
	UPROPERTY(EditAnywhere)
	float m_mouseSensitivity;

	friend class AMuertePlayerBase;

	TObjectPtr<AMuertePlayerBase> m_playerActor;

public:
	TObjectPtr<AMuertePlayerBase> GetPlayerActor();

	inline float GetMouseSensitivity() { return m_mouseSensitivity; }
};
