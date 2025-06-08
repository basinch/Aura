// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/BaseAuraCharacter.h"

ABaseAuraCharacter::ABaseAuraCharacter()
{
	PrimaryActorTick.bCanEverTick = false;

	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	Weapon->SetupAttachment(GetMesh(), FName("WeaponHandSocket"));
	Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

UAbilitySystemComponent* ABaseAuraCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystem;
}

void ABaseAuraCharacter::BeginPlay()
{
	Super::BeginPlay();
}


