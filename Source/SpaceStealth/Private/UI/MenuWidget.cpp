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
	CurrentMenu = EMenuSelection::Play;
}

void UMenuWidget::CloseSettings()
{
	SettingsBox->SetVisibility(ESlateVisibility::Hidden);
	MainMenuBox->SetVisibility(ESlateVisibility::Visible);
	CurrentSetting = ESettingsSelection::MasterVolume;
}

void UMenuWidget::MenuAdjustSlider(bool isLeftSlide)
{
	if (OpenMainMenu == EOpenMainMenu::SettingsMenu) 
	{
		if(UOverlay* Overlay = Cast<UOverlay>(SettingsBox->GetChildAt(static_cast<int>(CurrentSetting))))
		{
			if (USlider* Slider = Cast<USlider>(Overlay->GetChildAt(0)))
			{
				float Direction = isLeftSlide ? -1.0f : 1.0f;
				float NewValue = FMath::Clamp(Slider->GetValue() + Slider->GetStepSize()*Direction, Slider->GetMinValue(), Slider->GetMaxValue());
				Slider->SetValue(NewValue);
			}
		
		}
	}
}

void UMenuWidget::MenuDown()
{
	int32 NextIndex; 
	switch (OpenMainMenu)
	{
	case EOpenMainMenu::MainMenu:
		NextIndex = (static_cast<int32>(CurrentMenu) + 1) % static_cast<int32>(EMenuSelection::None);
		CurrentMenu = static_cast<EMenuSelection>(NextIndex);
		break;
	case EOpenMainMenu::SettingsMenu:
		NextIndex = (static_cast<int32>(CurrentSetting) + 1) % static_cast<int32>(ESettingsSelection::None);
		CurrentSetting = static_cast<ESettingsSelection>(NextIndex);
		break;
	}
}

void UMenuWidget::MenuUp()
{
	int32 MaxIndex; 
	int32 PreviousIndex;
	switch (OpenMainMenu)
	{
	case EOpenMainMenu::MainMenu:
		MaxIndex = static_cast<int32>(EMenuSelection::None);
		PreviousIndex = (static_cast<int32>(CurrentMenu) - 1 + MaxIndex) % MaxIndex;
		CurrentMenu = static_cast<EMenuSelection>(PreviousIndex);
		break;
	case EOpenMainMenu::SettingsMenu:
		MaxIndex = static_cast<int32>(ESettingsSelection::None);
		PreviousIndex = (static_cast<int32>(CurrentSetting) - 1 + MaxIndex) % MaxIndex;
		CurrentSetting = static_cast<ESettingsSelection>(PreviousIndex);
		break;
	default:
		break;
	}
}

void UMenuWidget::MenuSelection()
{
	switch (OpenMainMenu)
	{
	case EOpenMainMenu::MainMenu:
		switch (CurrentMenu)
		{
		case EMenuSelection::Play:
			PlayGame();
			break;
		case EMenuSelection::Settings:
			OpenSettings();
			break;
		case EMenuSelection::Exit:
			ExitGame();
			break;
		default:
			break;
		}
		break;
	case EOpenMainMenu::SettingsMenu:
		if (CurrentSetting == ESettingsSelection::BackToMainMenu)
		{
			CloseSettings();
			return;
		}
		break;
	default:
		break;
	}
}
