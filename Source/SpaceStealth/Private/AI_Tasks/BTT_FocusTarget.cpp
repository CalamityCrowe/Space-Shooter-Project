// Fill out your copyright notice in the Description page of Project Settings.


#include "AI_Tasks/BTT_FocusTarget.h"
#include "Controller/BaseEnemyController.h"
#include "BehaviorTree/BTFunctionLibrary.h"

UBTT_FocusTarget::UBTT_FocusTarget()
{
	NodeName = "Focus Target";
}
EBTNodeResult::Type UBTT_FocusTarget::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	if (ABaseEnemyController* Cont = Cast<ABaseEnemyController>(OwnerComp.GetAIOwner()))
	{
		AActor* act = UBTFunctionLibrary::GetBlackboardValueAsActor(this, TargetKey);
		if (act)
		{
			// Set the focus of the AI controller to the target actor
			Cont->SetFocus(act, EAIFocusPriority::Gameplay);
			return EBTNodeResult::Succeeded;
		}
	}
	return EBTNodeResult::Failed;
}
