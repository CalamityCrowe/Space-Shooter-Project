// Fill out your copyright notice in the Description page of Project Settings.


#include "Abilities/MoveAbility.h"
#include "Characters/PlayerCharacter.h"
#include <Kismet/KismetMathLibrary.h>
//#include "../SpaceStealth.h"

UMoveAbility::UMoveAbility()
{
	AbilityID = EAbilityInputID::Move;
	AbilityInputID = EAbilityInputID::Move;
}

void UMoveAbility::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);
	if (APlayerCharacter* PlayerCharacter = Cast<APlayerCharacter>(ActorInfo->AvatarActor.Get()))
	{
		if (CommitAbility(Handle, ActorInfo, ActivationInfo))
		{
			FVector2D Axis = PlayerCharacter->GetMovementAxis();
			FRotator ContRot = PlayerCharacter->GetControlRotation();
			const FVector XWorldVector = UKismetMathLibrary::GetRightVector(FRotator(0, ContRot.Yaw, ContRot.Roll));
			const FVector YWorldVector = UKismetMathLibrary::GetForwardVector(FRotator(0, ContRot.Yaw, 0));
			PlayerCharacter->AddMovementInput(XWorldVector, Axis.X, false);
			PlayerCharacter->AddMovementInput(YWorldVector, Axis.Y, false);
		}
	}
	EndAbility(Handle, ActorInfo, ActivationInfo, true, true); 
}
