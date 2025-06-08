// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/AuraCharacter.h"

#include "AbilitySystemComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Player/AuraPlayerState.h"


AAuraCharacter::AAuraCharacter()
{
	//SpringArm//
	SpringArm = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	SpringArm.Get()->SetupAttachment(GetRootComponent());
	SpringArm.Get()->bInheritPitch = false;
	SpringArm.Get()->bInheritYaw = false;
	SpringArm.Get()->bInheritRoll = false;
	
	//Camera//
	Camera = CreateDefaultSubobject<UCameraComponent>("Camera");
	Camera.Get()->SetupAttachment(SpringArm);

	//Movement//
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 400.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;
}

void AAuraCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void AAuraCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	//server init actor info
	SetInitAbilitySystem();
}

void AAuraCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();
	//client init actor info
	SetInitAbilitySystem();
}

void AAuraCharacter::SetInitAbilitySystem()
{
	AAuraPlayerState* AuraPlayerState = GetPlayerState<AAuraPlayerState>();
	check(AuraPlayerState);
	AuraPlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(AuraPlayerState, this);
	AbilitySystem = AuraPlayerState->GetAbilitySystemComponent();
	AttributeSet = AuraPlayerState->GetAttributeSet();
}

