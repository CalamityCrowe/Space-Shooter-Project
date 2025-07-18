// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/BaseCharacter.h"
#include "AbilitySystemComponent.h"
#include "Abilities/BaseAbility.h"
#include "Attributes/BaseAttributeSet.h"

// Sets default values
ABaseCharacter::ABaseCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ASC = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystemComponent"));

	BaseSet = CreateDefaultSubobject<UBaseAttributeSet>(TEXT("BaseAttributeSet"));


}

void ABaseCharacter::OnDamageTakenChanged(AActor* EffectInstigator, AActor* DamageCauser, const FGameplayTagContainer& GameplayTagContainer, float Damage)
{
	OnDamageTaken(EffectInstigator, DamageCauser, GameplayTagContainer, Damage);
}

// Called when the game starts or when spawned
void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();

	//BaseSet->OnDamageRecieved.AddUObject(this, &ABaseCharacter::OnDamageTakenChanged);

	if (ASC)
	{
		ASC->GetGameplayAttributeValueChangeDelegate(UBaseAttributeSet::GetHealthAttribute()).AddUObject(this, &ABaseCharacter::OnHealthAttributeChanged); 
	}
}

void ABaseCharacter::OnHealthAttributeChanged(const FOnAttributeChangeData& Data)
{
	OnHealthChanged(Data.OldValue, Data.NewValue); // this calls the blueprint implementation 
}

void ABaseCharacter::GetHealth(float& CurrentHealth, float& MaxHealth) const
{
	if (ASC)
	{
		if (const UBaseAttributeSet* Set = ASC->GetSet<UBaseAttributeSet>())
		{
			CurrentHealth = Set->GetHealth();
			MaxHealth = Set->GetMaxHealth();
		}
		else
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Attribute Set is not valid!"));
		}
	}
}

// Called every frame
void ABaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ABaseCharacter::InitializeAbilities()
{
	if (!ASC)
	{
#if WITH_EDITOR
		UE_LOG(LogTemp, Warning, TEXT("Ability System Component is not initialized for %s"), *GetName());
#endif
		return;
	}
	if (CharacterConfig)
	{
		for (TSubclassOf<UBaseAbility>& Ability : CharacterConfig->DefaultAbilities)
		{
			if (Ability)
			{
				FGameplayAbilitySpecHandle AbilityHandle = ASC->GiveAbility(FGameplayAbilitySpec(Ability, 1, static_cast<int32>(Ability.GetDefaultObject()->AbilityID), this));
			}
		}
	}

}
void ABaseCharacter::InitializeAttributes()
{
	if (!ASC)
	{
#if WITH_EDITOR
		UE_LOG(LogTemp, Warning, TEXT("Ability System Component is not initialized for %s"), *GetName());
#endif
	}
	if (CharacterConfig)
	{
		for (TSubclassOf<UGameplayEffect>& Effect : CharacterConfig->DefaultEffects)
		{
			if (Effect)
			{
				FGameplayEffectContextHandle EffectContext = ASC->MakeEffectContext();
				FGameplayEffectSpecHandle EffectSpecHandle = ASC->MakeOutgoingSpec(Effect, 1.0f, EffectContext);
				if (EffectSpecHandle.IsValid())
				{
					ASC->ApplyGameplayEffectSpecToSelf(*EffectSpecHandle.Data.Get());
				}
			}
		}
	}
}

void ABaseCharacter::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	if (ASC)
	{
		ASC->InitAbilityActorInfo(this, this);
		InitializeAbilities();
		InitializeAttributes();
	}
}

void ABaseCharacter::ComponentSetup()
{
}

