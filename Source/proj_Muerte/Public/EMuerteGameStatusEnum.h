// Copyright (c) 2025, DiscoveryGameWorks All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
UENUM(BlueprintType)
enum class EMuerteGameStatusEnum : uint8
{
	Title UMETA(DisplayName = "Title"),
	Interrogation UMETA(DisplayName = "Interogation"),
	InGame UMETA(DisplayName = "InGame"),
	GetCaught UMETA(DisplayName = "GetCaught"),
};
