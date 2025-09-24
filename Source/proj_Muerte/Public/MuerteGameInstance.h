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
	FVector2D m_mouseSensitivity;

	UPROPERTY(EditAnywhere)
	bool m_inverseMouseY;

	friend class AMuertePlayerBase;

	TObjectPtr<AMuertePlayerBase> m_playerActor;

public:
	TObjectPtr<AMuertePlayerBase> GetPlayerActor();

	inline const FVector2D GetMouseSensitivity() const { return m_mouseSensitivity; }

	inline const bool GetMouseInverseY() const { return m_inverseMouseY; }
};
