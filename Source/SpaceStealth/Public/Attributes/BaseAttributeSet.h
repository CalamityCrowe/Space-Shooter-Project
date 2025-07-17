// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSetDefinition.h"
#include "BaseAttributeSet.generated.h"

DECLARE_MULTICAST_DELEGATE_OneParam(FAttributeEventDamageRecieved,float)

/**
 * 
 */
UCLASS()
class SPACESTEALTH_API UBaseAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
	
public:
	UBaseAttributeSet();

	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, Health);
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, MaxHealth);
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, DamageRecieved);

	mutable FAttributeEvent OnOutOfHealth;
	mutable FAttributeEventDamageRecieved OnDamageRecieved;

protected:
	virtual bool PreGameplayEffectExecute(struct FGameplayEffectModCallbackData& Data) override;
	virtual void PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data) override;

	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
	virtual void PostAttributeChange(const FGameplayAttribute& Attribute, float OldValue, float NewValue) override;

private:
	bool bBlockHealthModification{ false }; 

	UPROPERTY(BlueprintReadOnly, Category = "Health", meta = (AllowPrivateAccess = true))
	FGameplayAttributeData Health;
	UPROPERTY(BlueprintReadOnly, Category = "Health", meta = (AllowPrivateAccess = true))
	FGameplayAttributeData MaxHealth;
	UPROPERTY(BlueprintReadOnly, Category = "Damage", meta = (AllowPrivateAccess = true))
	FGameplayAttributeData DamageRecieved;
};
