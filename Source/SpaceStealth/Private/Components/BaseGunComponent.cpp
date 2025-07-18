// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/BaseGunComponent.h"
#include <Kismet/GameplayStatics.h>

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
	if (GunData.CurrentAmmo > 0)
	{
		// Play fire animation
		if (FireAnimation && GetAnimInstance()->Montage_IsPlaying(FireAnimation) == false)
		{
			PlayAnimation(FireAnimation, false);
			GunData.CurrentAmmo--;
			// this is where the fire logic will be implemented, such as spawning a projectile or applying damage
		}
	}
	else
	{
		// Handle out of ammo case (e.g., play empty sound, show UI message, etc.)
		if (GunData.EmptyAmmoSound != nullptr)
		{
			UGameplayStatics::PlaySoundAtLocation(this, GunData.EmptyAmmoSound, GetComponentLocation());
		}
	}
}

void UBaseGunComponent::Reload()
{
}
