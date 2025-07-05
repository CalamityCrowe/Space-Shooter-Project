// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimNotify_PlaySound_AISense.h"

void UAnimNotify_PlaySound_AISense::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	OnNotified.Broadcast();
	Super::Notify(MeshComp, Animation, EventReference);
	if (APawn* Pawn = Cast<APawn>(MeshComp->GetOwner()))
	{
		Pawn->MakeNoise(1.0f, Pawn, MeshComp->GetComponentLocation());
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Notify: MakeNoise called!"));
	}

}
