// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/EnemyCharacter.h"
#include "Controller/BaseEnemyController.h"
#include "GameFramework/CharacterMovementComponent.h"

AEnemyCharacter::AEnemyCharacter()
{
}

void AEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void AEnemyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AEnemyCharacter::SetMovementSpeed_Implementation(EMovementSpeed NewMovementSpeed)
{
	switch(NewMovementSpeed)
	{
	case EMovementSpeed::Idle:
		GetCharacterMovement()->MaxWalkSpeed = 0.0f;
		break;
	case EMovementSpeed::Walking:
		GetCharacterMovement()->MaxWalkSpeed = 100.0f;
		break;
	case EMovementSpeed::Jogging:
		GetCharacterMovement()->MaxWalkSpeed = 300.0f;
		break;
	case EMovementSpeed::Running:
		GetCharacterMovement()->MaxWalkSpeed = 600.0f;
		break;
	}
}
