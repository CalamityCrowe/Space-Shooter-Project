// Fill out your copyright notice in the Description page of Project Settings.


#include "AI_Tasks/BTT_ClearFocus.h"
#include "Controller/BaseEnemyController.h"

UBTT_ClearFocus::UBTT_ClearFocus()
{
	NodeName = TEXT("Clear Focus");
}

EBTNodeResult::Type UBTT_ClearFocus::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{

	// Clear the focus of the AI controller
	if (ABaseEnemyController* Cont = Cast<ABaseEnemyController>(OwnerComp.GetAIOwner()))
	{
		Cont->ClearFocus(EAIFocusPriority::Gameplay);
		return EBTNodeResult::Succeeded;
	}

	return EBTNodeResult::Failed;
}