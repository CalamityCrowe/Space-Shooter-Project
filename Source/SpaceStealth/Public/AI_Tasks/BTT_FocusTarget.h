// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AI_Tasks/BTT_BaseTask.h"
#include "BTT_FocusTarget.generated.h"

/**
 * 
 */
UCLASS()
class SPACESTEALTH_API UBTT_FocusTarget : public UBTT_BaseTask
{
	GENERATED_BODY()
public:
	UBTT_FocusTarget();

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};
