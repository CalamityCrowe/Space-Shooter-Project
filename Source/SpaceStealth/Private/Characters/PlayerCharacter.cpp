// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/PlayerCharacter.h"
#include "../SpaceStealth.h"
#include "AbilitySystemComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/BaseGunComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "EnhancedInputComponent.h"

#include "EnhancedInputSubsystems.h"
#include "Kismet/KismetMathLibrary.h"

APlayerCharacter::APlayerCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	// Initialize Player Input Data
	PlayerInputData.MoveAction = nullptr;
	PlayerInputData.LookAction = nullptr;
	PlayerInputData.JumpAction = nullptr;
	PlayerInputData.InputMappingContext = nullptr;
	ComponentSetup(); 
}

void APlayerCharacter::OnDamageReceived(const FHitResult* HitResult, const float DamageAmount, AActor* HitInstigator)
{
	Super::OnDamageReceived(HitResult, DamageAmount, HitInstigator);

}

void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	if (APlayerController* PC = Cast<APlayerController>(GetController()))
	{
		if (UEnhancedInputLocalPlayerSubsystem* InputSystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PC->GetLocalPlayer()))
		{
			if (PlayerInputData.InputMappingContext == nullptr || PlayerAttackInput.InputMappingContext == nullptr)
			{
				return;
			}
			InputSystem->AddMappingContext(PlayerInputData.InputMappingContext, 0);
			InputSystem->AddMappingContext(PlayerAttackInput.InputMappingContext, 0);
		}
	}
	if (UEnhancedInputComponent* EIC = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EIC->BindAction(PlayerInputData.MoveAction, ETriggerEvent::Triggered, this, &APlayerCharacter::Move);
		EIC->BindAction(PlayerInputData.LookAction, ETriggerEvent::Triggered, this, &APlayerCharacter::Look);
		EIC->BindAction(PlayerInputData.JumpAction, ETriggerEvent::Triggered, this, &ACharacter::Jump);

		EIC->BindAction(PlayerAttackInput.AimAction, ETriggerEvent::Started, this, &APlayerCharacter::Aim);
		EIC->BindAction(PlayerAttackInput.AimAction, ETriggerEvent::Completed, this, &APlayerCharacter::Aim);

	}
}

void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APlayerCharacter::Move(const FInputActionValue& Value)
{
	MovementAxis = Value.Get<FVector2D>();
	SendAbilityLocalInput(Value, static_cast<int32>(EAbilityInputID::Move));	
}

void APlayerCharacter::Look(const FInputActionValue& Value)
{
	MouseAxis = Value.Get<FVector2D>();
	SendAbilityLocalInput(Value, static_cast<int32>(EAbilityInputID::Look));
}

void APlayerCharacter::Aim(const FInputActionValue& Value)
{
	bIsAiming = Value.Get<bool>();
	// do other camera work here, to give a better impression of the aiming working

}

/// <summary>
/// for this function, it is getting the input value passed into it, and then checking if the value is true or false.
/// 
/// If it is true, it will call the AbilityLocalInputPressed function on the Ability System Component with the inputID.
/// 
/// otherwise, it will call the AbilityLocalInputReleased function on the Ability System Component with the inputID.
/// 
/// This is basically how we will tell the ability component to activate certain abilities that require actual input from the player.
/// </summary>
void APlayerCharacter::SendAbilityLocalInput(const FInputActionValue& Value, int32 inputID)
{
	if(!ASC)
	{
#if WITH_EDITOR
		UE_LOG(LogTemp, Warning, TEXT("Ability System Component is not initialized for %s"), *GetName());
#endif
		return;
	}
	if (Value.Get<bool>()) 
	{
		ASC->AbilityLocalInputPressed(inputID);

	}
	else
	{
		ASC->AbilityLocalInputReleased(inputID);
	}
}

void APlayerCharacter::ComponentSetup()
{
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArmComponent->SetupAttachment(RootComponent);
	Camera->SetupAttachment(SpringArmComponent);

	SpringArmComponent->TargetArmLength = 300.0f; // Set the distance of the camera from the player
	SpringArmComponent->bUsePawnControlRotation = true; // Rotate the arm based on the controller's rotation
	SpringArmComponent->SocketOffset = FVector(60.0f, 40.0f, 0.0f); // Offset the camera slightly above the player

	GunComponent = CreateDefaultSubobject<UBaseGunComponent>(TEXT("GunComponent"));
	GunComponent->SetupAttachment(GetMesh());

}
