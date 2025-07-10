// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Enums/EnemyEnums.h"
#include "BaseEnemyController.generated.h"

class UAIPerceptionComponent;

/**
 *
 */
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

	UFUNCTION()
	void CanSenseActor(AActor* Actor, EAISenses SenseType, bool& OutSense, FAIStimulus& OutStimulus);

	UFUNCTION()
	void HandleSensedSight(AActor* Actor, const FAIStimulus& Stimulus);
	UFUNCTION()
	void HandleSensedSound(const FAIStimulus& Stimulus);
	UFUNCTION()
	void HandleSensedDamage(AActor* Actor, const FAIStimulus& Stimulus);

public:
	UFUNCTION(BlueprintPure)
	EAIStates GetCurrentAIState();
	UFUNCTION(BlueprintCallable)
	void SetStateAsPassive();
	UFUNCTION(BlueprintCallable)
	void SetStateAsAttacking(UObject* AttackTarget);
	UFUNCTION(BlueprintCallable)
	void SetStateAsInvestigating(FVector POI);

};
