// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/BaseGunComponent.h"
#include <Kismet/GameplayStatics.h>
#include <Characters/PlayerCharacter.h>
#include "AbilitySystemComponent.h"
#include "Abilities/BaseAbility.h"

UBaseGunComponent::UBaseGunComponent()
{
	PrimaryComponentTick.bCanEverTick = false; // Disable ticking for this component


	// Set the skeletal mesh for the gun (optional, can be set in editor)
	SetSkeletalMesh(nullptr);

}

void UBaseGunComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UBaseGunComponent::Fire()
{
	if (GunData->CurrentAmmo > 0)
	{
		// Play fire animation
		if (FireAnimation && GetAnimInstance()->Montage_IsPlaying(FireAnimation) == false)
		{
			PlayAnimation(FireAnimation, false);
			GunData->CurrentAmmo--;
			// this is where the fire logic will be implemented, such as spawning a projectile or applying damage
		}
	}
	else
	{
		// Handle out of ammo case (e.g., play empty sound, show UI message, etc.)
		if (GunData->EmptyAmmoSound != nullptr)
		{
			UGameplayStatics::PlaySoundAtLocation(this, GunData->EmptyAmmoSound, GetComponentLocation());
		}
	}
}

void UBaseGunComponent::Reload()
{
}

void UBaseGunComponent::GrantAbilities()
{
	if (GunData->Abilities.Num() > 0)
	{
		if (APlayerCharacter* PC = Cast<APlayerCharacter>(GetOwner())) 
		{
			for (TSubclassOf<UBaseAbility>& Ability: GunData->Abilities)
			{
				if(Ability)
				{
					UAbilitySystemComponent* AbilitySystem = PC->GetAbilitySystemComponent();
					FGameplayAbilitySpecHandle AbilityHandle = AbilitySystem->GiveAbility(FGameplayAbilitySpec(Ability, 1, static_cast<int32>(Ability.GetDefaultObject()->AbilityID), PC));
				}
			}
		}
	}

}
