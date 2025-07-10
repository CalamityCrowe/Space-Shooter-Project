// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BTT_BaseTask.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class SPACESTEALTH_API UBTT_BaseTask : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
public:
	UBTT_BaseTask();

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

};
