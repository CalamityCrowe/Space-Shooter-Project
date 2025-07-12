// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimNotifies/ANS_AttackNotify.h"
#include "Characters/BaseCharacter.h"
UANS_AttackNotify::UANS_AttackNotify()
{
	NotifyColor = FColor(255, 100, 100, 255); // Red color for attack notify
	bShouldFireInEditor = true; // Allow firing in editor for testing purposes
}

void UANS_AttackNotify::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration, const FAnimNotifyEventReference& EventReference)
{
}

void UANS_AttackNotify::NotifyTick(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float FrameDeltaTime, const FAnimNotifyEventReference& EventReference)
{
	if(ABaseCharacter* CharRef = Cast<ABaseCharacter>(MeshComp->GetOwner()))
	{
		// do hit logic here
	}

}

void UANS_AttackNotify::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
}
