// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Enums/AbilityEnums.h"
#include "BaseAbility.generated.h"

/**
 *
 */
UCLASS()
class SPACESTEALTH_API UBaseAbility : public UGameplayAbility
{
	GENERATED_BODY()
public:
	UBaseAbility();
	UPROPERTY(EditAnywhere, Category = "Ability|Input")
	EAbilityInputID AbilityInputID{ EAbilityInputID::None };
	UPROPERTY(EditAnywhere, Category = "Ability|Input")
	EAbilityInputID AbilityID{ EAbilityInputID::None };

	UPROPERTY(EditAnywhere, Category = "Ability")
	bool bActivateAbilityOnGranted = false;
	UPROPERTY(EditAnywhere, Category = "Ability")
	float Cost{0};
	UPROPERTY(EditAnywhere, Category = "Ability")
	float CooldownDuration{0};

	virtual void OnAvatarSet(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec) override;


};
