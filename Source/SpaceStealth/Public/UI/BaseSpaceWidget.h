// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BaseSpaceWidget.generated.h"

/**
 * 
 */
UCLASS()
class SPACESTEALTH_API UBaseSpaceWidget : public UUserWidget
{
	GENERATED_UCLASS_BODY()
public:
	UBaseSpaceWidget(); 

	virtual void NativeConstruct() override; 
};
