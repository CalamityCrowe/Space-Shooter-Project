// Fill out your copyright notice in the Description page of Project Settings.


#include "Abilities/BaseAbility.h"
#include "AbilitySystemComponent.h"
#include "GameplayTagContainer.h"

UBaseAbility::UBaseAbility()
{
	InstancingPolicy = EGameplayAbilityInstancingPolicy::InstancedPerActor;

	ActivationBlockedTags.AddTag(FGameplayTag::RequestGameplayTag(FName("State.Dead")));
	ActivationBlockedTags.AddTag(FGameplayTag::RequestGameplayTag(FName("Ability.Cooldown")));
}

void UBaseAbility::OnAvatarSet(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec)
{
	Super::OnAvatarSet(ActorInfo, Spec);
	if (bActivateAbilityOnGranted && ActorInfo->AvatarActor.IsValid())
	{
		// Activate the ability immediately when granted
		ActorInfo->AbilitySystemComponent->TryActivateAbility(Spec.Handle);
	}
}
