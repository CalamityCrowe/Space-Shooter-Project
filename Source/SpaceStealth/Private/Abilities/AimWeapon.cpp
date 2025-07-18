// Fill out your copyright notice in the Description page of Project Settings.


#include "Abilities/AimWeapon.h"
#include "Characters/PlayerCharacter.h"

UAimWeapon::UAimWeapon()
{
	AbilityID = EAbilityInputID::Aim;
	AbilityInputID = EAbilityInputID::Aim;
}

void UAimWeapon::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

	if (APlayerCharacter* PlayerCharacter = Cast<APlayerCharacter>(ActorInfo->AvatarActor.Get()))
	{
		if (PlayerCharacter->IsAiming())
		{
			PlayerCharacter->OnAimStarted();
		}
	}

}
void UAimWeapon::EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled)
{
	Super::EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);
	if (APlayerCharacter* PlayerCharacter = Cast<APlayerCharacter>(ActorInfo->AvatarActor.Get()))
	{

		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Aim Ended"));
		PlayerCharacter->OnAimEnded();

	}
}

void UAimWeapon::InputReleased(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo)
{
	Super::InputReleased(Handle, ActorInfo, ActivationInfo);
	//if (Cast<APlayerCharacter>(ActorInfo->AvatarActor.Get())->IsAiming() == false)
	//	return;

	EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
}
