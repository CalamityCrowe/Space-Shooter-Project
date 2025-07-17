// Fill out your copyright notice in the Description page of Project Settings.


#include "Attributes/BaseAttributeSet.h"
#include "GameplayEffectExtension.h"

UBaseAttributeSet::UBaseAttributeSet()
{
}

bool UBaseAttributeSet::PreGameplayEffectExecute(struct FGameplayEffectModCallbackData& Data)
{
	if (!Super::PreGameplayEffectExecute(Data))
	{
		return false;
	}
	return true; 
}

void UBaseAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data); 
}

void UBaseAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	if (Attribute == GetHealthAttribute() && bBlockHealthModification) 
	{
		NewValue = GetHealth(); // Prevent health modification if blocked
	}
}

void UBaseAttributeSet::PostAttributeChange(const FGameplayAttribute& Attribute, float OldValue, float NewValue)
{
	if (Attribute == GetDamageRecievedAttribute()) 
	{
		const float CurrentHealth = GetHealth();	
		const float NewHealth = CurrentHealth - NewValue;
		SetHealth(NewHealth);
	}

	if (Attribute == GetMaxHealthAttribute())
	{
		SetHealth(FMath::Clamp(NewValue, 0.0f, GetMaxHealth()));
	}
}
