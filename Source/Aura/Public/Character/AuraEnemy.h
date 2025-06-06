// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/BaseAuraCharacter.h"
#include "Interface/TargetInterface.h"
#include "AuraEnemy.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API AAuraEnemy : public ABaseAuraCharacter, public ITargetInterface
{
	GENERATED_BODY()
public:
	virtual void HighlightTarget() override;
	virtual void UnHighlightTarget() override;

	UPROPERTY(BlueprintReadOnly)
	bool bHighlighted = false;
};
