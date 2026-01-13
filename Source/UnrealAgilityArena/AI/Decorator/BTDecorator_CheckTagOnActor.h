// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "BTDecorator_CheckTagOnActor.generated.h"

/**
 * 
 */
UCLASS()
class UNREALAGILITYARENA_API UBTDecorator_CheckTagOnActor : public UBTDecorator
{
	GENERATED_BODY()
	
public:
	UBTDecorator_CheckTagOnActor();
	
protected:
	UPROPERTY(EditAnywhere, Category="TagCheck")
	FBlackboardKeySelector ActorToCheck;
	UPROPERTY(EditAnywhere, Category="TagCheck")
	FName TagName;
	
	virtual bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const override;
	virtual void InitializeFromAsset(UBehaviorTree& Asset) override;
	
	
};
