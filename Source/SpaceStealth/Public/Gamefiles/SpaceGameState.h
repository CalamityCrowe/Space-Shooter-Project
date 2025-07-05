// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "SpaceGameState.generated.h"

/**
 * 
 */
UCLASS()
class SPACESTEALTH_API ASpaceGameState : public AGameStateBase
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	ASpaceGameState();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game State")
	int32 PlayerScore;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game State")
	int32 EnemyCount;

};
