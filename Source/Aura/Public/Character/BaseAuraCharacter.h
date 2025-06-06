// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BaseAuraCharacter.generated.h"

UCLASS(Abstract)
class AURA_API ABaseAuraCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ABaseAuraCharacter();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category= "Combat")
	TObjectPtr<USkeletalMeshComponent> Weapon;
};
