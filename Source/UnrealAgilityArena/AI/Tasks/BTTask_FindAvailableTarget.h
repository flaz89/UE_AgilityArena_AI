// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_FindAvailableTarget.generated.h"

/**
 * 
 */
UCLASS()
class UNREALAGILITYARENA_API UBTTask_FindAvailableTarget : public UBTTaskNode
{
	GENERATED_BODY()
	
public:
	UBTTask_FindAvailableTarget();
	
	UPROPERTY(EditAnywhere, Category="Blackboard")
	FBlackboardKeySelector TargetActor;
	
	UPROPERTY(EditAnywhere, Category="Blackboard")
	FName TargetTag;
	
protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	
	
	
	
	
};
