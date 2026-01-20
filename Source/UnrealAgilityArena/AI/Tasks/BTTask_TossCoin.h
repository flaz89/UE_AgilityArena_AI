// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_TossCoin.generated.h"

/**
 * 
 */
UCLASS()
class UNREALAGILITYARENA_API UBTTask_TossCoin : public UBTTaskNode
{
	GENERATED_BODY()
	
public:
	UBTTask_TossCoin();
	
	UPROPERTY(EditAnywhere, Category="Blackboard")
	FBlackboardKeySelector KeySelector;
	
	UPROPERTY(EditAnywhere, Category="Task")
	float TrueProbability = 0.5f;
	
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};
