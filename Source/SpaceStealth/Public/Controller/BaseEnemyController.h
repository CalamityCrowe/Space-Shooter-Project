// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "BaseEnemyController.generated.h"

class UAIPerceptionComponent;

/**
 * 
 */
UENUM(BlueprintType)
enum class EMovementSpeed : uint8
{
	Idle UMETA(DisplayName = "Idle"),
	Walking UMETA(DisplayName = "Walking"),
	Jogging UMETA(DisplayName = "Jogging"),
	Running UMETA(DisplayName = "Running"),
};
UENUM(BlueprintType)
enum class EAIStates : uint8
{
	Passive UMETA(DisplayName = "Passive"),
	Attacking UMETA(DisplayName = "Attacking"),
	Investigating UMETA(DisplayName = "Investigating"),
	Frozen UMETA(DisplayName = "Frozen"),
	Dead UMETA(DisplayName = "Dead"),
};
UENUM(BlueprintType)
enum class EAISenses : uint8 {
	None UMETA(DisplayName = "None"),
	Sight UMETA(DisplayName = "Sight"),
	Hearing UMETA(DisplayName = "Hearing"),
	Damage UMETA(DisplayName = "Damage"),
};

UCLASS()
class SPACESTEALTH_API ABaseEnemyController : public AAIController
{
	GENERATED_BODY()
	
public:
	ABaseEnemyController();
protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
private:

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Blackboard|Keys", meta = (AllowPrivateAccess = true))
	FName TargetKeyName;
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Blackboard|Keys", meta = (AllowPrivateAccess = true))
	FName POIKeyName;
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Blackboard|Keys", meta = (AllowPrivateAccess = true))
	FName AIStateKeyName; 
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Blackboard|Behaviour Trees", meta = (AllowPrivateAccess = true))
	TObjectPtr<UBehaviorTree> BehaviourTree;
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Components", meta = (AllowPrivateAccess = true))
	TObjectPtr<UAIPerceptionComponent> AIPerceptionComponent;

	UFUNCTION()
	void OnUpdatedPerception(const TArray<AActor*>& UpdatedActors);

public:
	UFUNCTION(BlueprintCallable)
	void SetStateAsPassive();
	UFUNCTION(BlueprintCallable)
	void SetStateAsAttacking(UObject* AttackTarget);
	UFUNCTION(BlueprintCallable)
	void SetStateAsInvestigating(FVector POI);

};
