// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_FindAvailableTarget.h"

#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"
#include "UnrealAgilityArena/Actors/BaseTarget.h"

UBTTask_FindAvailableTarget::UBTTask_FindAvailableTarget()
{
	NodeName = "Find Available Target";
	TargetActor.AddObjectFilter(this, GET_MEMBER_NAME_CHECKED(UBTTask_FindAvailableTarget, TargetActor), AActor::StaticClass());
	TargetActor.SelectedKeyName = FBlackboard::KeySelf;
}

EBTNodeResult::Type UBTTask_FindAvailableTarget::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	// extract the Blackboard and check its existence
	const TObjectPtr<UBlackboardComponent> BlackboardComp = OwnerComp.GetBlackboardComponent();
	if (BlackboardComp == nullptr) return EBTNodeResult::Failed;
	
	// create an AActor array to store alla actors with specific tag in te level
	TArray<AActor*> TargetList;
	UGameplayStatics::GetAllActorsWithTag(this, TargetTag, TargetList);
	if (TargetList.Num() == 0) return EBTNodeResult::Failed;
	
	// extract a random actor from the target and sat as value of TargetActor 
	const TObjectPtr<AActor> RandomTarget = TargetList[FMath::RandRange(0, TargetList.Num() - 1)];
	BlackboardComp->SetValueAsObject(TargetActor.SelectedKeyName, RandomTarget);
	
	return EBTNodeResult::Succeeded;
}
