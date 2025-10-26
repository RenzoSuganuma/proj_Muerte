// Copyright (c) 2025, DiscoveryGameWorks All Rights Reserved.


#include "MuerteInGameWidgetBase.h"

#include "Components/TextBlock.h"

void UMuerteInGameWidgetBase::NativeConstruct()
{
	Super::NativeConstruct();
}

void UMuerteInGameWidgetBase::SetObjectiveText(const FText& content)
{
	UTextBlock* text = Cast<UTextBlock>(GetWidgetFromName(FName(TEXT("ObjectiveText"))));
	text->SetText(content);
}
