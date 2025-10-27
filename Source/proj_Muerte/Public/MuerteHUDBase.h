// Copyright (c) 2025, DiscoveryGameWorks All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "MuerteInGameWidgetBase.h"
#include "GameFramework/HUD.h"
#include "MuerteHUDBase.generated.h"

// MuerteのHUD基底クラス
UCLASS()
class PROJ_MUERTE_API AMuerteHUDBase : public AHUD
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	TSubclassOf<UUserWidget> m_widget;

	TObjectPtr<UMuerteInGameWidgetBase> m_interface;

	virtual void BeginPlay() override;

public:
	TObjectPtr<UMuerteInGameWidgetBase> GetWidget() const;
};
