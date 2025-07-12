// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/MeleeComponent.h"
#include "Characters/BaseCharacter.h"
#include "Kismet/KismetSystemLibrary.h"

// Sets default values for this component's properties
UMeleeComponent::UMeleeComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UMeleeComponent::BeginPlay()
{
	Super::BeginPlay();
	if (CharacterReference = Cast<ABaseCharacter>(GetOwner()))
	{
		
	}
}

void UMeleeComponent::HitDetect()
{
	if (SocketName.IsNone())
	{
		UE_LOG(LogTemp, Warning, TEXT("SocketName is not set! Please set a valid socket name for melee hit detection."));
		return;
	}
	FVector start = CharacterReference->GetMesh()->GetSocketLocation(SocketName);
	TArray<TEnumAsByte<EObjectTypeQuery>> objectTypes;
	objectTypes.Add(UEngineTypes::ConvertToObjectType(ECollisionChannel::ECC_Pawn));

	TArray<AActor*> actorsToIgnore;
	actorsToIgnore.Add(CharacterReference);
	TArray<FHitResult> hits;

	UKismetSystemLibrary::SphereTraceMultiForObjects(GetWorld(), start, start, HitRadius, objectTypes, false, actorsToIgnore, EDrawDebugTrace::None, hits, true);
#if WITH_EDITOR
	DrawDebugSphere(GetWorld(), start, HitRadius, 12, FColor::Red, false, 1.0f);
#endif
	if (hits.Num() > 0)
	{
		for (FHitResult hit : hits)
		{
			if (ABaseCharacter* HitCharacter = Cast<ABaseCharacter>(hit.GetActor()))
			{
				// Hit Logic here
				// Example: HitCharacter->TakeDamage(DamageAmount, FDamageEvent(), CharacterReference->GetController(), this);
				UE_LOG(LogTemp, Log, TEXT("Hit %s with melee attack!"), *HitCharacter->GetName());
			}
		}
	}
}


