// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AI_Tasks/BTT_BaseTask.h"
#include "BTT_ClearFocus.generated.h"

/**
 * 
 */
UCLASS()
class SPACESTEALTH_API UBTT_ClearFocus : public UBTT_BaseTask
{
	GENERATED_BODY()
public:
	UBTT_ClearFocus();

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;


};
