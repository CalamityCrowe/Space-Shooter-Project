// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/BaseAbility.h"
#include "MoveAbility.generated.h"

/**
 * 
 */
UCLASS()
class SPACESTEALTH_API UMoveAbility : public UBaseAbility
{
	GENERATED_BODY()
public: 
	UMoveAbility();

	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;
};
