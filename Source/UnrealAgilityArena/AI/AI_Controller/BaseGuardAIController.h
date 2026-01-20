// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "BaseGuardAIController.generated.h"

struct FAIStimulus;

UCLASS()
class UNREALAGILITYARENA_API ABaseGuardAIController : public AAIController
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ABaseGuardAIController();
	
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void OnTargetPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
