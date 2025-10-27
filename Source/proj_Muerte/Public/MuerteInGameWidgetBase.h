// Copyright (c) 2025, DiscoveryGameWorks All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "MuerteInGameWidgetBase.generated.h"

/**
 * 
 */
UCLASS()
class PROJ_MUERTE_API UMuerteInGameWidgetBase : public UUserWidget
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere)
	FName m_objectiveTextName;
	TObjectPtr<UTextBlock> m_objectiveText;

	virtual void NativeConstruct() override;

public:
	UFUNCTION(BlueprintCallable)
	void SetObjectiveText(const FText& content);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void HideFadePanel();
	virtual void HideFadePanel_Implementation();
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void ShowFadePanel();
	virtual void ShowFadePanel_Implementation();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void ShowTitlePanel();
	virtual void ShowTitlePanel_Implementation();
};
