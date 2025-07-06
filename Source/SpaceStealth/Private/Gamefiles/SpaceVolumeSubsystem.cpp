// Fill out your copyright notice in the Description page of Project Settings.


#include "Gamefiles/SpaceVolumeSubsystem.h"

void USpaceVolumeSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("SpaceVolumeSubsystem Initialized"));
}

void USpaceVolumeSubsystem::Deinitialize()
{
	Super::Deinitialize();
}
