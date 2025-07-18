// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/BaseAbility.h"
#include "LookAbility.generated.h"

/**
 * 
 */
UCLASS()
class SPACESTEALTH_API ULookAbility : public UBaseAbility
{
	GENERATED_BODY()
public: 
	ULookAbility();

	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;

	
};
