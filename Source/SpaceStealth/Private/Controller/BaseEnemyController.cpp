// Fill out your copyright notice in the Description page of Project Settings.


#include "Controller/BaseEnemyController.h"
#include "Perception/AIPerceptionComponent.h"

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

	// Initialize any necessary variables or states here

}

void ABaseEnemyController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABaseEnemyController::OnUpdatedPerception(const TArray<AActor*>& UpdatedActors)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Perception Updated!"));
}

void ABaseEnemyController::SetStateAsPassive()
{
}

void ABaseEnemyController::SetStateAsAttacking(UObject* AttackTarget)
{
}

void ABaseEnemyController::SetStateAsInvestigating(FVector POI)
{
}
