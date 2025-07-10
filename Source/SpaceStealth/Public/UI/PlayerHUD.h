// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/BaseSpaceWidget.h"
#include "PlayerHUD.generated.h"


class UProgressBar;
class UTextBlock;
class UOverlay;
/**
 * 
 */
UCLASS()
class SPACESTEALTH_API UPlayerHUD : public UBaseSpaceWidget
{
	GENERATED_UCLASS_BODY()
public:
	UPlayerHUD();

	virtual void NativeConstruct() override;

	UFUNCTION(BlueprintCallable)
	void UpdateHealthBar(float CurrentHealth, float MaxHealth);
	
	void UpdateBar(float CurrentValue, float MaxValue, UProgressBar* ProgressBar, UTextBlock* TextBlock);

private:
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UProgressBar> HealthBar;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UTextBlock> HealthText;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UOverlay> HealthOverlay;

};
