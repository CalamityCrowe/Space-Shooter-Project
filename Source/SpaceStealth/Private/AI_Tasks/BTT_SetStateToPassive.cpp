// Fill out your copyright notice in the Description page of Project Settings.


#include "AI_Tasks/BTT_SetStateToPassive.h"
#include "Controller/BaseEnemyController.h"

UBTT_SetStateToPassive::UBTT_SetStateToPassive()
{
	NodeName = TEXT("Set State To Passive");
}
EBTNodeResult::Type UBTT_SetStateToPassive::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	if (ABaseEnemyController* Controller = Cast<ABaseEnemyController>(OwnerComp.GetAIOwner()))
	{
		Controller->SetStateAsPassive();
		return EBTNodeResult::Succeeded;
	}
	return EBTNodeResult::Failed;
}