// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "SpaceVolumeSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class SPACESTEALTH_API USpaceVolumeSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "Audio|Volume")
	void SetMasterVolume(float Volume) {MasterVolume = FMath::Clamp(Volume, 0.0f, 1.0f);}
	UFUNCTION(BlueprintCallable, Category = "Audio|Volume")
	void SetMusicVolume(float Volume) { MusicVolume = FMath::Clamp(Volume, 0.0f, 1.0f); }
	UFUNCTION(BlueprintCallable, Category = "Audio|Volume")
	void SetSFXVolume(float Volume) { SFXVolume = FMath::Clamp(Volume, 0.0f, 1.0f); }
	UFUNCTION(BLueprintPure, Category = "Audio|Volume")
	float GetMasterVolume() const { return MasterVolume; }
	UFUNCTION(BlueprintPure, Category = "Audio|Volume")
	float GetMusicVolume() const { return MusicVolume; }
	UFUNCTION(BlueprintPure, Category = "Audio|Volume")
	float GetSFXVolume() const { return SFXVolume; }

private:
	float MasterVolume = 0.5f;
	float MusicVolume = 0.5f;
	float SFXVolume = 0.5f;
};
