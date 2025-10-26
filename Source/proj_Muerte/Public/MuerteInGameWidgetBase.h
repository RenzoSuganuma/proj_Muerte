// Copyright (c) 2025, DiscoveryGameWorks All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MuerteInGameWidgetBase.generated.h"

/**
 * 
 */
UCLASS()
class PROJ_MUERTE_API UMuerteInGameWidgetBase : public UUserWidget
{
	GENERATED_BODY()

	virtual void NativeConstruct() override;

public:
	UFUNCTION(BlueprintCallable)
	void SetObjectiveText(const FText& content);
};
