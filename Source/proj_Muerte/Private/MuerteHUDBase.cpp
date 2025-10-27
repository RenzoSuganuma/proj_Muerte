// Copyright (c) 2025, DiscoveryGameWorks All Rights Reserved.

#include "MuerteHUDBase.h"

void AMuerteHUDBase::BeginPlay()
{
	auto widget = CreateWidget(GetOwningPlayerController(), m_widget.Get());
	widget->AddToPlayerScreen(0);

	if (UMuerteInGameWidgetBase* temp = Cast<UMuerteInGameWidgetBase>(widget))
	{
		m_interface = temp;
		m_interface->SetObjectiveText(FText::FromString(TEXT("出口を見つける")));
	}

	Super::BeginPlay();
}

TObjectPtr<UMuerteInGameWidgetBase> AMuerteHUDBase::GetWidget() const
{
	return m_interface;
}
