// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AI_Tasks/BTT_BaseTask.h"
#include "Enums/EnemyEnums.h"
#include "BTT_SetMovementSpeed.generated.h"

/**
 * 
 */
UCLASS()
class SPACESTEALTH_API UBTT_SetMovementSpeed : public UBTT_BaseTask
{
	GENERATED_BODY()
public:
	UBTT_SetMovementSpeed();

	virtual  EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
private:
	UPROPERTY(EditAnywhere, Category = "Movement Speed", meta = (AllowPrivateAccess = "true"))
	EMovementSpeed MovementSpeed; // Default to Normal speed
};
