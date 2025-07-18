// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/BaseCharacter.h"
#include "PlayerCharacter.generated.h"


class UInputAction; 
class UInputMappingContext;
class UCameraComponent;
class USpringArmComponent;
class UBaseGunComponent;
class UPlayerHUD;	
/**
 * 
 */
UCLASS(BlueprintType)
class SPACESTEALTH_API UPlayerInputData : public UDataAsset
{
	GENERATED_BODY()
public :

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	TObjectPtr<UInputAction> MoveAction;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	TObjectPtr<UInputAction> LookAction;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	TObjectPtr<UInputAction> JumpAction;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	TObjectPtr<UInputMappingContext> InputMappingContext;
};

UCLASS(BlueprintType)
class SPACESTEALTH_API UPlayerAttackInput : public UDataAsset
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	TObjectPtr<UInputAction> FireAction;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	TObjectPtr<UInputAction> ReloadAction;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	TObjectPtr<UInputAction> AimAction;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	TObjectPtr<UInputMappingContext> InputMappingContext;
};

UCLASS()
class SPACESTEALTH_API APlayerCharacter : public ABaseCharacter
{
	GENERATED_BODY()
public:
	APlayerCharacter();

	virtual void BeginPlay() override;

	virtual void OnDamageTakenChanged(AActor* EffectInstigator, AActor* DamageCauser, const FGameplayTagContainer& GameplayTagContainer, float Damage);


	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	TObjectPtr<UPlayerInputData> PlayerInputData;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	TObjectPtr<UPlayerAttackInput> PlayerAttackInput;

	FVector2D GetMovementAxis() const { return MovementAxis; }
	FVector2D GetLookAxis() const { return MouseAxis; }
	UFUNCTION(BlueprintPure)
	bool IsAiming() const { return bIsAiming; }

	UFUNCTION(BlueprintImplementableEvent)
	void OnAimStarted();
	UFUNCTION(BlueprintImplementableEvent)
	void OnAimEnded();

protected:
	virtual void SendAbilityLocalInput(const FInputActionValue& Value,int32 inputID);

	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly, Category = "UI",meta = (AllowPrivateAccess = true))
	TSubclassOf<UPlayerHUD> PlayerHUDRef;

	UPlayerHUD* PlayerHUD;

private:
	virtual void ComponentSetup() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gun", meta = (AllowPrivateAccess = true))
	TObjectPtr<UBaseGunComponent> GunComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = true))
	TObjectPtr<UCameraComponent> Camera;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = true))
	TObjectPtr<USpringArmComponent> SpringArmComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gun", meta = (AllowPrivateAccess = true))
	TObjectPtr<UAnimMontage> FireAnimation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gun", meta = (AllowPrivateAccess = true))
	FName AttachSocket;

	bool bIsAiming; 

	FVector2D MovementAxis; 
	FVector2D MouseAxis;

	UFUNCTION()
	void Move(const FInputActionValue& Value);
	UFUNCTION()
	void Look(const FInputActionValue& Value);
	UFUNCTION()
	void Aim(const FInputActionValue& Value);

	
};
