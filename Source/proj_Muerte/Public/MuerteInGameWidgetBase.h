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

	UPROPERTY(EditAnywhere)
	FName m_interrogationTextName;
	TObjectPtr<UTextBlock> m_interrogationText;

	UPROPERTY(EditAnywhere)
	FName m_select1TextName;
	TObjectPtr<UTextBlock> m_select1Text;

	UPROPERTY(EditAnywhere)
	FName m_select2TextName;
	TObjectPtr<UTextBlock> m_select2Text;

	UPROPERTY(EditAnywhere)
	FName m_select3TextName;
	TObjectPtr<UTextBlock> m_select3Text;

	virtual void NativeConstruct() override;

public:
	UFUNCTION(BlueprintCallable)
	void SetObjectiveText(FText content);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void HideInGamePanel();
	virtual void HideInGamePanel_Implementation();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void ShowInGamePanel();
	virtual void ShowInGamePanel_Implementation();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void ShowTitlePanel();
	virtual void ShowTitlePanel_Implementation();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void ShowInterrogationPanel();
	virtual void ShowInterrogationPanel_Implementation();
};
