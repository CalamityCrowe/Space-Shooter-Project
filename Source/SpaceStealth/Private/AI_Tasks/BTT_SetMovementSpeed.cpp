// Fill out your copyright notice in the Description page of Project Settings.


#include "AI_Tasks/BTT_SetMovementSpeed.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "Interface/EnemyInterface.h"

UBTT_SetMovementSpeed::UBTT_SetMovementSpeed()
{
	NodeName = TEXT("Set Movement Speed");
}

EBTNodeResult::Type UBTT_SetMovementSpeed::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	
	if(OwnerComp.GetAIOwner()->GetPawn()->GetClass()->ImplementsInterface(UEnemyInterface::StaticClass()))
	{
		IEnemyInterface::Execute_SetMovementSpeed(OwnerComp.GetAIOwner()->GetPawn(), MovementSpeed);
		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("Movement Speed set to: %s"), *UEnum::GetValueAsString(MovementSpeed)));
		return EBTNodeResult::Succeeded;
	}
	return EBTNodeResult::Failed;
}
