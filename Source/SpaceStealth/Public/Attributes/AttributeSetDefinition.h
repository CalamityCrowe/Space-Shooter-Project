#pragma once
#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AttributeSet.h"


#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

DECLARE_MULTICAST_DELEGATE_FourParams(FAttributeEvent, AActor* /*Instigator*/, AActor* /*Causer*/, const FGameplayEffectSpec& /*EffectSpec*/, float /*EffectMagnitude*/);