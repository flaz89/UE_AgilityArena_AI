// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "BTService_SetAmmo.generated.h"

/**
 * 
 */
UCLASS()
class UNREALAGILITYARENA_API UBTService_SetAmmo : public UBTService
{
	GENERATED_BODY()
	
public:
	UBTService_SetAmmo();
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Blackboard")
	FBlackboardKeySelector NeedsReload;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Blackboard")
	bool bKeyValue = false;
	
	
	virtual void OnBecomeRelevant(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};
