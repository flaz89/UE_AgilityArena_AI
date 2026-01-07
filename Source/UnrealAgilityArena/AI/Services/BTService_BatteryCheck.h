// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "BTService_BatteryCheck.generated.h"

enum class EBatteryStatus : uint8;
class ABaseDummyCharacter;
/**
 * 
 */
UCLASS()
class UNREALAGILITYARENA_API UBTService_BatteryCheck : public UBTService
{
	GENERATED_BODY()
	
public:
	UBTService_BatteryCheck();
	
protected:
	
	UPROPERTY()
	UBlackboardComponent* BlackboardComp = nullptr;
	UPROPERTY()
	ABaseDummyCharacter* ControlledCharacter = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Blackboard")
	FBlackboardKeySelector IsLowOnBatteryKey;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Blackboard")
	FBlackboardKeySelector IsBatteryDepletedKey;
	
	virtual void OnBecomeRelevant(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	virtual void OnCeaseRelevant(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	UFUNCTION()
	void OnBatteryStatusChange(EBatteryStatus NewBatteryStatus);
};
