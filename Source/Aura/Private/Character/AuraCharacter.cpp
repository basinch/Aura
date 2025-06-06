// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/AuraCharacter.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"


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
