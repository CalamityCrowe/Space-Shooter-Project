// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SkeletalMeshComponent.h"
#include "BaseGunComponent.generated.h"


class USoundBase;
class UBaseAbility; 

/**
 * 
 */

UCLASS(BlueprintType)
class SPACESTEALTH_API UGunData : public UDataAsset
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gun Data")
	int32 MagazineSize;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gun Data")
	float Damage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gun Data")
	int32 CurrentAmmo;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gun Data")
	int32 MaxExtraAmmo;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gun Data|Empty Ammo Sound")
	TObjectPtr<USoundBase> EmptyAmmoSound;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gun Data|Abilities", meta = (AllowPrivateAccess = true))
	TArray<TSubclassOf<UBaseAbility>> Abilities;

	UGunData()
		: MagazineSize(30), Damage(10.0f), CurrentAmmo(30), MaxExtraAmmo(90), EmptyAmmoSound(nullptr)
	{
	}
};

UCLASS()
class SPACESTEALTH_API UBaseGunComponent : public USkeletalMeshComponent
{
	GENERATED_BODY()
public:
	UBaseGunComponent();

	// Called when the game starts
	virtual void BeginPlay() override;

	// Function to fire the gun
	UFUNCTION(BlueprintCallable, Category = "Gun")
	void Fire();

	// Function to reload the gun
	UFUNCTION(BlueprintCallable, Category = "Gun")
	void Reload();

	void GrantAbilities();

	UGunData* GetGunData() const { return GunData; }

private:
	UPROPERTY(EditAnywhere,Category = "Animations",meta = (AllowPrivateAccess = true))
	TObjectPtr<UAnimMontage> FireAnimation;
	
	UPROPERTY(EditAnywhere, Category = "Gun Data", meta = (AllowPrivateAccess = true))
	TObjectPtr<UGunData> GunData;

	
	
};
