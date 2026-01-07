// Fill out your copyright notice in the Description page of Project Settings.


#include "UnrealAgilityArena/AI/AI_Controller/BaseDummyAIController.h"

void ABaseDummyAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	//if BehaviorTree exists (ensureMsgf) execute it
	if (ensureMsgf(BehaviorTree, TEXT("Behavior Three isa a nullptr! Please add BehaviorThree in your AI controlller")))
	{
		RunBehaviorTree(BehaviorTree);
	}
}

