// Fill out your copyright notice in the Description page of Project Settings.


#include "AI_Tasks/BTT_FocusTarget.h"
#include "Controller/BaseEnemyController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Object.h"
#include "Characters/BaseCharacter.h"

UBTT_FocusTarget::UBTT_FocusTarget()
{
	NodeName = "Focus Target";
}
EBTNodeResult::Type UBTT_FocusTarget::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    const UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
    AAIController* AIController = OwnerComp.GetAIOwner();
    if (AIController && BlackboardComp)
    {
        if (BlackboardKey.SelectedKeyType == UBlackboardKeyType_Object::StaticClass())
        {
            UObject* KeyValue = BlackboardComp->GetValue<UBlackboardKeyType_Object>(BlackboardKey.GetSelectedKeyID());
            if (AActor* act = Cast<AActor>(KeyValue))
            {
                AIController->SetFocus(act, EAIFocusPriority::Gameplay);
                return EBTNodeResult::Succeeded;
            }
        }
    }
    return EBTNodeResult::Failed;
}
