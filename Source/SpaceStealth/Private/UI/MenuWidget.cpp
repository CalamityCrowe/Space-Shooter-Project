// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/MenuWidget.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Components/VerticalBox.h"
#include "Components/Slider.h"
#include "Components/Overlay.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/GameplayStatics.h"


UMenuWidget::UMenuWidget(const FObjectInitializer& Object) :Super(Object)
{

}

void UMenuWidget::NativeConstruct()
{
	Super::NativeConstruct();
	PlaytText->SetText(FText::FromString("Play"));
	SettingsText->SetText(FText::FromString("Settings"));
	ExitText->SetText(FText::FromString("Exit"));

	PlayButton->OnClicked.AddDynamic(this, &UMenuWidget::PlayGame);
	SettingsButton->OnClicked.AddDynamic(this, &UMenuWidget::OpenSettings);
	ExitButton->OnClicked.AddDynamic(this, &UMenuWidget::ExitGame);

	// needs to widget colour stuff to show what menu is selected?
	MainMenuBox->SetVisibility(ESlateVisibility::Visible);
	SettingsBox->SetVisibility(ESlateVisibility::Hidden);
}

void UMenuWidget::ExitGame()
{
	if (GEngine)
	{
		UKismetSystemLibrary::QuitGame(this, nullptr, EQuitPreference::Quit, true);
	}
}

void UMenuWidget::PlayGame()
{
	/*
	* Do the stuff for game instance here
	*/
	UGameplayStatics::OpenLevelBySoftObjectPtr(this, LevelToLoad, true); 
}

void UMenuWidget::OpenSettings()
{
	SettingsBox->SetVisibility(ESlateVisibility::Visible);
	MainMenuBox->SetVisibility(ESlateVisibility::Hidden);
	CurrentMenuIndex = 1;
}

void UMenuWidget::CloseSettings()
{
	SettingsBox->SetVisibility(ESlateVisibility::Hidden);
	MainMenuBox->SetVisibility(ESlateVisibility::Visible);
	CurrentSettingsIndex = 0;
}

void UMenuWidget::MenuLeft()
{
}

void UMenuWidget::MenuRight()
{
}

void UMenuWidget::MenuDown()
{
}

void UMenuWidget::MenuUp()
{
}

void UMenuWidget::MenuSelection()
{
	
}
