// Fill out your copyright notice in the Description page of Project Settings.


#include "UnrealAgilityArena/AI/Tasks/BTTask_FindRandomLocation.h"

#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"

EBTNodeResult::Type UBTTask_FindRandomLocation::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	// check if exists a Blackboard on the owner if not FAILED
	const TObjectPtr<UBlackboardComponent> BlackboardComp = OwnerComp.GetBlackboardComponent();
	if (BlackboardComp == nullptr) return EBTNodeResult::Failed;
	
	// create an array with Actors with a specific tag, if array is empty FAILED
	TArray<AActor*> TargetList;
	UGameplayStatics::GetAllActorsWithTag(GetWorld(), TargetTag, TargetList);
	if (TargetList.Num() == 0) return EBTNodeResult::Failed;
	
	// if exist a Blackboard owner, Target array isn't empty, select a random actor target from the array and 
	// set the Blackboard key "TargetLocation" value with its actor location value
	const AActor* RandomTarget = TargetList[FMath::RandRange(0, TargetList.Num() - 1)];
	BlackboardComp -> SetValueAsVector(BlackboardKey.SelectedKeyName, RandomTarget->GetActorLocation());
	
	return EBTNodeResult::Succeeded;
}
