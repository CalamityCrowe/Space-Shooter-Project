// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/BaseSpaceWidget.h"
#include "MenuWidget.generated.h"


class UTextBlock;
class UButton;
class UVerticalBox;
class USlider;
class UMaterialInstance; 


UENUM(BlueprintType)
enum class EMenuSelection : uint8
{
	Play,
	Settings,
	Exit
};
UENUM(BlueprintType)
enum class ESettingsSelection : uint8
{
	MasterVolume,
	MusicVolume,
	EffectsVolume, 
	BackToMainMenu
};
UENUM(BlueprintType)
enum class EOpenMainMenu : uint8
{
	MainMenu UMETA(DisplayName = "Main Menu"),
	SettingsMenu UMETA(DisplayName = "Settings Menu")
};


UCLASS()
class SPACESTEALTH_API UMenuWidget : public UBaseSpaceWidget
{
	GENERATED_UCLASS_BODY()
public: 
	UMenuWidget(); 

	virtual void NativeConstruct() override;

private:
	// when doing the bind widget, the name must match the name in the UMG editor or it will have a compile error in the editor

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "UI|Vertical Box", Meta = (BindWidget,AllowPrivateAccess = true))
	TObjectPtr<UVerticalBox> MainMenuBox; 
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "UI|Vertical Box", Meta = (BindWidget, AllowPrivateAccess = true))
	TObjectPtr<UVerticalBox> SettingsBox;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "UI|Button", Meta = (BindWidget, AllowPrivateAccess = true))
	TObjectPtr<UButton> PlayButton;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "UI|Button", Meta = (BindWidget, AllowPrivateAccess = true))
	TObjectPtr<UButton> SettingsButton;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "UI|Button", Meta = (BindWidget, AllowPrivateAccess = true))
	TObjectPtr<UButton> ExitButton;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "UI|Text", Meta = (BindWidget, AllowPrivateAccess = true))
	TObjectPtr<UTextBlock> PlaytText;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "UI|Text", Meta = (BindWidget, AllowPrivateAccess = true))
	TObjectPtr<UTextBlock> SettingsText;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "UI|Text", Meta = (BindWidget, AllowPrivateAccess = true))
	TObjectPtr<UTextBlock> ExitText;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "UI|Slider", Meta = (BindWidget, AllowPrivateAccess = true))
	TObjectPtr<USlider> MasterVolume;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "UI|Slider", Meta = (BindWidget, AllowPrivateAccess = true))
	TObjectPtr<USlider> MusicVolume;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "UI|Slider", Meta = (BindWidget, AllowPrivateAccess = true))
	TObjectPtr<USlider> EffectsVolume;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "UI|Select Material", Meta = (BindWidget, AllowPrivateAccess = true))
	TObjectPtr<UMaterialInstance> ButtonMaterial;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "UI|Select Material", Meta = (BindWidget, AllowPrivateAccess = true))
	FLinearColor ButtonColor;
	
	EMenuSelection CurrentMenuIndex; // 0 = Main Menu, 1 = Settings Menu
	ESettingsSelection CurrentSettingsIndex; 

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "UI", Meta = (AllowPrivateAccess = true))
	const TSoftObjectPtr<UWorld> LevelToLoad;

public:
	UFUNCTION(BlueprintCallable)
	void ExitGame(); 
	UFUNCTION(BlueprintCallable)
	void PlayGame();
	UFUNCTION(BlueprintCallable)
	void OpenSettings();

	UFUNCTION()
	void CloseSettings();
	UFUNCTION(BlueprintCallable)
	void MenuLeft();
	UFUNCTION(BlueprintCallable)
	void MenuRight();


	UFUNCTION(BlueprintCallable)
	void MenuDown();
	UFUNCTION(BlueprintCallable)
	void MenuUp();
	UFUNCTION(BlueprintCallable)
	void MenuSelection();

};
