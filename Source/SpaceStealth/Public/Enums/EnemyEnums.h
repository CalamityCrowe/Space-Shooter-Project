// Fill out your copyright notice in the Description page of Project Settings.
#pragma once
#include "CoreMinimal.h"
#include "EnemyEnums.generated.h"

UENUM(BlueprintType)
enum class EMovementSpeed : uint8
{
	Idle UMETA(DisplayName = "Idle"),
	Walking UMETA(DisplayName = "Walking"),
	Jogging UMETA(DisplayName = "Jogging"),
	Running UMETA(DisplayName = "Running"),
};
UENUM(BlueprintType)
enum class EAIStates : uint8
{
	Passive UMETA(DisplayName = "Passive"),
	Attacking UMETA(DisplayName = "Attacking"),
	Investigating UMETA(DisplayName = "Investigating"),
	Frozen UMETA(DisplayName = "Frozen"),
	Dead UMETA(DisplayName = "Dead"),
};
UENUM(BlueprintType)
enum class EAISenses : uint8 {
	None UMETA(DisplayName = "None"),
	Sight UMETA(DisplayName = "Sight"),
	Hearing UMETA(DisplayName = "Hearing"),
	Damage UMETA(DisplayName = "Damage"),
};
