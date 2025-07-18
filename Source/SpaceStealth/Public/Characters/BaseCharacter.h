// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "GameplayEffect.h"
#include "BaseCharacter.generated.h"

class UBaseAbility; 
class UGameplayEffect;


UCLASS(BlueprintType)
class SPACESTEALTH_API UCharacterConfig : public UDataAsset
{
	GENERATED_BODY()
public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "GAS")
	TArray<TSubclassOf<UBaseAbility>> DefaultAbilities;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "GAS")
	TArray<TSubclassOf<UGameplayEffect>> DefaultEffects;
};


UCLASS()
class SPACESTEALTH_API ABaseCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABaseCharacter();

	virtual void OnDamageReceived(const struct FHitResult* HitResult, const float DamageAmount, AActor* HitInstigator) {}

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override { return ASC; }
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "GAS")
	TObjectPtr<UCharacterConfig> CharacterConfig;

	virtual void OnHealthAttributeChanged(const FOnAttributeChangeData& Data);
	UFUNCTION(BlueprintImplementableEvent, Category = "GAS")
	void OnHealthChanged(float OldHealth, float NewHealth);

	virtual void ComponentSetup();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "GAS", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UAbilitySystemComponent> ASC;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void InitializeAbilities();		
	virtual void InitializeAttributes();

	virtual void PostInitializeComponents() override;

};
