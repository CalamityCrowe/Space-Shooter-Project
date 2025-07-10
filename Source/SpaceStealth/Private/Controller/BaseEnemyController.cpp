// Fill out your copyright notice in the Description page of Project Settings.


#include "Controller/BaseEnemyController.h"
#include "Perception/AIPerceptionComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include <Kismet/GameplayStatics.h>
#include "GameFramework/Character.h"
#include "Perception/AIPerceptionSystem.h"
#include "Perception/AISense_Hearing.h"
#include "Perception/AISense_Sight.h"
#include "Perception/AISense_Damage.h"

ABaseEnemyController::ABaseEnemyController()
{
	// Set this controller to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AIPerceptionComponent = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("AIPerceptionComponent"));
	AIPerceptionComponent->OnPerceptionUpdated.AddDynamic(this, &ABaseEnemyController::OnUpdatedPerception);
	
	// Initialize any necessary components or variables here

}

void ABaseEnemyController::BeginPlay()
{
	Super::BeginPlay();
	if(BehaviourTree)
	{
		RunBehaviorTree(BehaviourTree);
		SetStateAsPassive();
	}
}

void ABaseEnemyController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABaseEnemyController::OnUpdatedPerception(const TArray<AActor*>& UpdatedActors)
{
	//for (AActor* actor: UpdatedActors)
	//{
	//	//if(!IsValid(actor))
	//	//{
	//	//	continue;
	//	//}
	//	//bool OutSight = false;
	//	//FAIStimulus OutSightStimulus;
	//	//CanSenseActor(actor, EAISenses::Sight, OutSight, OutSightStimulus);
	//	//if (OutSight)
	//	//{
	//	//	// Handle sight perception
	//	//	SetStateAsAttacking(actor);
	//	//	return;
	//	//}
	//}
}

/// <summary>
///  this function handles if the target actor can be sensed by the AI perception component.
///  It checks each of the last sensed stimuli for the specified sense type (Sight, Hearing, Damage) and returns whether the actor was successfully sensed.
/// </summary>
void ABaseEnemyController::CanSenseActor(AActor* Actor, EAISenses SenseType, bool& OutSense, FAIStimulus& OutStimulus)
{
	FActorPerceptionBlueprintInfo PerceptionInfo;
	AIPerceptionComponent->GetActorsPerception(Actor, PerceptionInfo); 
	for (const FAIStimulus& Stimulus : PerceptionInfo.LastSensedStimuli)
	{
		TSubclassOf<UAISense> FoundSense = UAIPerceptionSystem::GetSenseClassForStimulus(GetWorld(), Stimulus);
		switch (SenseType)
		{
			case EAISenses::Sight:
				if (FoundSense == UAISense_Sight::StaticClass())
				{
					OutSense = Stimulus.WasSuccessfullySensed();
					OutStimulus = Stimulus;
					return;
				}
				break;
			case EAISenses::Hearing:
				if (FoundSense == UAISense_Hearing::StaticClass())
				{
					OutSense = Stimulus.WasSuccessfullySensed();
					OutStimulus = Stimulus;
					return;
				}
				break;
			case EAISenses::Damage:
				if (FoundSense == UAISense_Damage::StaticClass())
				{
					OutSense = Stimulus.WasSuccessfullySensed();
					OutStimulus = Stimulus;
					return;
				}
				break;
			default:
				break;
		}
	}
}

void ABaseEnemyController::HandleSensedSight(AActor* Actor, FAIStimulus Stimulus)
{
	switch(GetCurrentAIState())
	{
	case EAIStates::Passive:
		SetStateAsAttacking(Actor);
		break;
	case EAIStates::Investigating:
		SetStateAsAttacking(Actor);
		break;
	case EAIStates::Attacking:
		// Already attacking, no change needed
		break;
	default:
		// Handle other states if necessary
		break;
	}
}

void ABaseEnemyController::HandleSensedSound(FAIStimulus Stimulus)
{
	switch (GetCurrentAIState())
	{
	case EAIStates::Passive:
		SetStateAsInvestigating(Stimulus.StimulusLocation);
		break;
	case EAIStates::Investigating:
		SetStateAsInvestigating(Stimulus.StimulusLocation);
		break;
	default:
		break;
	}
}

void ABaseEnemyController::HandleSensedDamage(AActor* Actor, FAIStimulus Stimulus)
{
	switch (GetCurrentAIState())
	{
	case EAIStates::Passive:
		SetStateAsAttacking(Actor);
		break;
	case EAIStates::Investigating:
		SetStateAsAttacking(Actor);
		break;
	case EAIStates::Attacking:
		// Already attacking, no change needed
		break;
	default:
		// Handle other states if necessary
		break;
	}
}



EAIStates ABaseEnemyController::GetCurrentAIState() 
{
	return static_cast<EAIStates>(Blackboard->GetValueAsEnum(AIStateKeyName));

	//return static_cast<EAIStates>(Blackboard->GetValueAsEnum(AIStateKeyName));
}

void ABaseEnemyController::SetStateAsPassive()
{
	Blackboard->SetValueAsEnum(AIStateKeyName, static_cast<uint8>(EAIStates::Passive));
}

void ABaseEnemyController::SetStateAsAttacking(UObject* AttackTarget)
{
	if (AttackTarget)
	{
		Blackboard->SetValueAsObject(TargetKeyName, AttackTarget);
	}
	Blackboard->SetValueAsEnum(AIStateKeyName, static_cast<uint8>(EAIStates::Attacking));
}

void ABaseEnemyController::SetStateAsInvestigating(FVector POI)
{
	Blackboard->SetValueAsVector(POIKeyName, POI);
	Blackboard->SetValueAsEnum(AIStateKeyName, static_cast<uint8>(EAIStates::Investigating));
}
