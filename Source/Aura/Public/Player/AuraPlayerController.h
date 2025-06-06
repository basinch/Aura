// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "AuraPlayerController.generated.h"

class UInputMappingContext;
class UInputAction;
struct FInputActionValue;
class ITargetInterface;
/**
 * 
 */
UCLASS()
class AURA_API AAuraPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AAuraPlayerController();
	virtual void Tick(float DeltaTime) override;
protected:
	virtual void SetupInputComponent() override;
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere, Category = "Input");
	TObjectPtr<UInputMappingContext> AuraContext;
	
	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> MoveAction;

	void Move(const struct FInputActionValue& ActionValue);

	void CursorTrace();

	TScriptInterface<ITargetInterface> LastActor;
	TScriptInterface<ITargetInterface> CurrentActor;
};
