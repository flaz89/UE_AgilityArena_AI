// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "BaseSecurityCamAIController.generated.h"

struct FAIStimulus;

UCLASS(Blueprintable)
class UNREALAGILITYARENA_API ABaseSecurityCamAIController : public AAIController
{
	GENERATED_BODY()

public:
	ABaseSecurityCamAIController();

protected:
	virtual void BeginPlay() override;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Dummy AI Controller")
	TObjectPtr<UBehaviorTree> UBehaviorTree;
	
	virtual void OnPossess(APawn* InPawn) override;
	
	UFUNCTION()
	void OnTargetPerceptionUpdate(AActor* Actor, FAIStimulus Stimulus);
	
};
