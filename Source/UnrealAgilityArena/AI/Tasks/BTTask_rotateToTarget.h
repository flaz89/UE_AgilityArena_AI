// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_rotateToTarget.generated.h"

/**
 * 
 */
UCLASS()
class UNREALAGILITYARENA_API UBTTask_RotateToTarget : public UBTTaskNode
{
	GENERATED_BODY()
	
public:
	UBTTask_RotateToTarget();
	
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	
	UPROPERTY(EditAnywhere, Category="Blackboard")
	FBlackboardKeySelector TargetActor;
	
};
