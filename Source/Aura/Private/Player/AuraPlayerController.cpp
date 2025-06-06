// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/AuraPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Interface/TargetInterface.h"

AAuraPlayerController::AAuraPlayerController()
{
	//Replication//
	bReplicates = true;
}

void AAuraPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	CursorTrace();
}

void AAuraPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	
	//Input action binding//
	UEnhancedInputComponent* EnhancedInputComponent= CastChecked<UEnhancedInputComponent>(InputComponent);
	
	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AAuraPlayerController::Move);
}

void AAuraPlayerController::BeginPlay()
{
	Super::BeginPlay();
	check(AuraContext);
	
	//Input mapping//
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	check(Subsystem);
	Subsystem->AddMappingContext(AuraContext, 0);

	//Input mode cursor visibility etc.//
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;
	FInputModeGameAndUI InputModeData;
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputModeData.SetHideCursorDuringCapture(false);
	SetInputMode(InputModeData);
}

void AAuraPlayerController::Move(const struct FInputActionValue& ActionValue)
{
	//Get movement axis values//
	const FVector2D InputAxisVector = ActionValue.Get<FVector2D>();
	const FRotator Rotation = GetControlRotation();
	const FRotator YawRotation(0.f, Rotation.Yaw, 0.f);

	const FVector ForwardVector = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightVector = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
	
	//Apply movement input//
	if (APawn* ControlledPawn = GetPawn<APawn>())
	{
		ControlledPawn->AddMovementInput(ForwardVector, InputAxisVector.Y);
		ControlledPawn->AddMovementInput(RightVector, InputAxisVector.X);
	}
}

void AAuraPlayerController::CursorTrace()
{
	FHitResult CursorHit;
	GetHitResultUnderCursor(ECC_Visibility, false, CursorHit);
	if (!CursorHit.bBlockingHit) return;

	LastActor = CurrentActor;
	CurrentActor = CursorHit.GetActor();

	if (!LastActor)
	{
		if (CurrentActor)
		{
			CurrentActor->HighlightTarget();
		}
		else
		{
		}
	}
	else
	{
		if (!CurrentActor)
		{
			LastActor->UnHighlightTarget();
		}
		else
		{
			if (LastActor != CurrentActor)
			{
				LastActor->UnHighlightTarget();
				CurrentActor->HighlightTarget();
			}
			else
			{
			}
		}
	}
}

