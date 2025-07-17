// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType)
enum class EAbilityInputID :uint8
{
	None UMETA(DisplayName = "None"),
	Confirm UMETA(DisplayName = "Confirm"),
	Cancel UMETA(DisplayName = "Cancel"),
	Fire UMETA(DisplayName = "Fire"),
	Aim UMETA(DisplayName = "Aim"),

	Sprint UMETA(DisplayName = "Sprint"),
	Move UMETA(DisplayName = "Move"),
	Look UMETA(DisplayName = "Look"),
};