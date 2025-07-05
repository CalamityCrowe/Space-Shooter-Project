// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BTT_ClearFocus.generated.h"

/**
 * 
 */
UCLASS()
class SPACESTEALTH_API UBTT_ClearFocus : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
public:
	UBTT_ClearFocus(const FObjectInitializer& ObjectInitializer);

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;


};
