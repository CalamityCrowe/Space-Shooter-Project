// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MeleeComponent.generated.h"

class ABaseCharacter; 

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SPACESTEALTH_API UMeleeComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMeleeComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	UFUNCTION(BlueprintCallable)
	void HitDetect();
private:
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category = "Hit Detection References",meta = (AllowPrivateAccess = true))
	TObjectPtr<ABaseCharacter> CharacterReference;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Hit Detection References", meta = (AllowPrivateAccess = true))
	FName SocketName;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Hit Detection References", meta = (AllowPrivateAccess = true))
	float HitRadius = 10.0f; // Default radius for melee hit detection
};
