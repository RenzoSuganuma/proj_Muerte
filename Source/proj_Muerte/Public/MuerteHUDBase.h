// Copyright (c) 2025, DiscoveryGameWorks All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "MuerteHUDBase.generated.h"

class UMuerteInGameInterface;

// MuerteのHUD基底クラス
UCLASS()
class PROJ_MUERTE_API AMuerteHUDBase : public AHUD
{
	GENERATED_BODY()

	TObjectPtr<UMuerteInGameInterface> m_interface;
	
	virtual void BeginPlay() override;
};
