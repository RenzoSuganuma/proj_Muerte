// Copyright (c) 2025, DiscoveryGameWorks All Rights Reserved.

#include "MuerteHUDBase.h"

void AMuerteHUDBase::BeginPlay()
{
	m_interface = CreateWidget(GetOwningPlayerController(), m_widget.Get());
	m_interface->AddToPlayerScreen(0);

	Super::BeginPlay();
}
