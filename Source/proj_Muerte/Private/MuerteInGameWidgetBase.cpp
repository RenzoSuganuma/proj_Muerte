// Copyright (c) 2025, DiscoveryGameWorks All Rights Reserved.


#include "MuerteInGameWidgetBase.h"

#include "Components/TextBlock.h"

void UMuerteInGameWidgetBase::NativeConstruct()
{
	Super::NativeConstruct();

	m_objectiveText = Cast<UTextBlock>(GetWidgetFromName(m_objectiveTextName));
	m_interrogationText = Cast<UTextBlock>(GetWidgetFromName(m_interrogationTextName));
	m_select1Text = Cast<UTextBlock>(GetWidgetFromName(m_select1TextName));
	m_select2Text = Cast<UTextBlock>(GetWidgetFromName(m_select2TextName));
	m_select3Text = Cast<UTextBlock>(GetWidgetFromName(m_select3TextName));

	ShowTitlePanel();
}

void UMuerteInGameWidgetBase::SetObjectiveText(FText content)
{
	m_objectiveText->SetText(content);
}

void UMuerteInGameWidgetBase::HideInGamePanel_Implementation()
{
	// ブループリント側からコールされる
}

void UMuerteInGameWidgetBase::ShowInGamePanel_Implementation()
{
	// ブループリント側からコールされる
}

void UMuerteInGameWidgetBase::ShowTitlePanel_Implementation()
{
	// ブループリント側からコールされる
}

void UMuerteInGameWidgetBase::ShowInterrogationPanel_Implementation()
{
	// ブループリント側からコールされる
}
