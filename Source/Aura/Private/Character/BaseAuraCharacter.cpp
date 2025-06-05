// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/BaseAuraCharacter.h"

ABaseAuraCharacter::ABaseAuraCharacter()
{
	PrimaryActorTick.bCanEverTick = false;
}

void ABaseAuraCharacter::BeginPlay()
{
	Super::BeginPlay();
}


