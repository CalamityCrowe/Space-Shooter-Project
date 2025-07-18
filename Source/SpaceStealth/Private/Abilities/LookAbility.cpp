// Fill out your copyright notice in the Description page of Project Settings.


#include "Abilities/LookAbility.h"
#include "Characters/PlayerCharacter.h"
#include <Kismet/KismetMathLibrary.h>

ULookAbility::ULookAbility()
{
	AbilityID = EAbilityInputID::Look;
	AbilityInputID = EAbilityInputID::Look;
}

void ULookAbility::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
	if (APlayerCharacter* Character = Cast<APlayerCharacter>(ActorInfo->AvatarActor.Get()))
	{
		if (CommitAbility(Handle, ActorInfo, ActivationInfo))
		{
			FVector2D Axis = Character->GetLookAxis();
			FRotator ContRot = Character->GetControlRotation();
			if(APlayerController* PC =  Cast<APlayerController>(Character->GetController()))
			{
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Look Axis: %s"), *Axis.ToString()));
				PC->AddYawInput(Axis.X);
				PC->AddPitchInput(Axis.Y);
			}
		}
	}
	EndAbility(Handle, ActorInfo, ActivationInfo, true, true);
}
