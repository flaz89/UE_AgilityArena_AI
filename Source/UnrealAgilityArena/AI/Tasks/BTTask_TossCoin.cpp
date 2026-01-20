// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_TossCoin.h"

#include "BehaviorTree/BlackboardComponent.h"

UBTTask_TossCoin::UBTTask_TossCoin()
{
	NodeName = "Toss Coin";
	
}

EBTNodeResult::Type UBTTask_TossCoin::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	if (BlackboardComp == nullptr) return EBTNodeResult::Failed;
	
	const float RandomNum = FMath::RandRange(0.0f, 1.0f);
	
	BlackboardComp->SetValueAsBool(KeySelector.SelectedKeyName, RandomNum < TrueProbability );
	
	return EBTNodeResult::Succeeded;
}
