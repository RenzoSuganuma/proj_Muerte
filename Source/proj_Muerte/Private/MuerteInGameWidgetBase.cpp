// Copyright (c) 2025, DiscoveryGameWorks All Rights Reserved.


#include "MuerteInGameWidgetBase.h"

#include "Components/TextBlock.h"

void UMuerteInGameWidgetBase::NativeConstruct()
{
	Super::NativeConstruct();

	m_objectiveText = Cast<UTextBlock>(GetWidgetFromName(m_objectiveTextName));

	ShowTitlePanel();
}

void UMuerteInGameWidgetBase::SetObjectiveText(FText content)
{
	m_objectiveText->SetText(content);
}

void UMuerteInGameWidgetBase::HideFadePanel_Implementation()
{
	// ブループリント側からコールされる
}

void UMuerteInGameWidgetBase::ShowFadePanel_Implementation()
{
	// ブループリント側からコールされる
}

void UMuerteInGameWidgetBase::ShowTitlePanel_Implementation()
{
	// ブループリント側からコールされる
}
