// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/PlayerHUD.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"
#include "Components/Overlay.h"

UPlayerHUD::UPlayerHUD(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
}

void UPlayerHUD::NativeConstruct()
{
	Super::NativeConstruct();
}

void UPlayerHUD::UpdateHealthBar(float CurrentHealth, float MaxHealth)
{
	if (IsValid(HealthBar) && IsValid(HealthText))
	{
		UpdateBar(CurrentHealth, MaxHealth, HealthBar, HealthText);
	}
}

void UPlayerHUD::UpdateBar(float CurrentValue, float MaxValue, UProgressBar* ProgressBar, UTextBlock* TextBlock)
{
	float Percentage = MaxValue > 0 ? CurrentValue / MaxValue : 0.0f;
	if (ProgressBar)
	{
		ProgressBar->SetPercent(Percentage);
	}
	if (TextBlock)
	{
		FString Text = FString::Printf(TEXT("%.1f / %.1f"), CurrentValue, MaxValue);
		TextBlock->SetText(FText::FromString(Text));
	}
}
