// Copyright (c) 2025, DiscoveryGameWorks All Rights Reserved.


#include "MuerteInGameWidgetBase.h"
#include "Components/TextBlock.h"

void UMuerteInGameWidgetBase::NativeConstruct()
{
	Super::NativeConstruct();

	m_objectiveText = Cast<UTextBlock>(GetWidgetFromName(m_objectiveTextName));

	ShowFadePanel();
}

void UMuerteInGameWidgetBase::SetObjectiveText(const FText& content)
{
	m_objectiveText->SetText(content);
}

void UMuerteInGameWidgetBase::HideFadePanel_Implementation()
{
}

void UMuerteInGameWidgetBase::ShowFadePanel_Implementation()
{
}
