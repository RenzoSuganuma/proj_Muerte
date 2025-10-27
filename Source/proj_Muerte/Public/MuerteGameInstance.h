// Copyright (c) 2025, DiscoveryGameWorks All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EMuerteGameStatusEnum.h"
#include "Engine/GameInstance.h"
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

	EMuerteGameStatusEnum m_status;

public:
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGameStatusChanged, EMuerteGameStatusEnum, newStatus);

	FOnGameStatusChanged OnGameStatusChanged;

	// 関数シグネチャ
	FVector2D GetMouseSensitivity() const { return m_mouseSensitivity; }
	bool GetMouseInverseY() const { return m_inverseMouseY; }

	UFUNCTION(BlueprintCallable)
	void SetGameStatus(EMuerteGameStatusEnum newStatus)
	{
		m_status = newStatus;
		OnGameStatusChanged.Broadcast(newStatus);
	}

	UFUNCTION(BlueprintCallable)
	EMuerteGameStatusEnum GetGameStatus() const { return m_status; }
};
