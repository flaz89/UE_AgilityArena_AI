// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "BaseDummyAIController.generated.h"

/**
 * 
 */
UCLASS()
class UNREALAGILITYARENA_API ABaseDummyAIController : public AAIController
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AI Controller")
	TObjectPtr<UBehaviorTree> BehaviorTree;

	virtual void OnPossess(APawn* InPawn) override;
	
	UFUNCTION()
	void OnPawnDamaged( AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser );
	
};

