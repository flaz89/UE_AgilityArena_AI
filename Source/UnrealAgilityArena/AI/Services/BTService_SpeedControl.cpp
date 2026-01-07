// Fill out your copyright notice in the Description page of Project Settings.


#include "UnrealAgilityArena/AI/Services/BTService_SpeedControl.h"

#include "UnrealAgilityArena/AI/BaseDummyCharacter.h"
#include "UnrealAgilityArena/AI/AI_Controller/BaseDummyAIController.h"


void UBTService_SpeedControl::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
	
	// check if AI Controller exists casting to custom AI Controller (ABaseDummyAIController), if not exit
	const ABaseDummyAIController* AIController = Cast<ABaseDummyAIController>(OwnerComp.GetAIOwner());
	if (!AIController) return;
	
	// check if Character exists casting to custom Character (ABaseDummyCharacter), if not exit
	ABaseDummyCharacter* ControlledCharacter = Cast<ABaseDummyCharacter>(AIController->GetPawn());
	if (!ControlledCharacter) return;

	// if Character with AI Controller exist check battery status and set speed movement
	switch (ControlledCharacter -> GetBatteryStatus())
	{
		case EBatteryStatus::EBS_Empty:
			break;
		case EBatteryStatus::EBS_Low:
			ControlledCharacter->SetWalkSpeed();
			break;
		case EBatteryStatus::EBS_Medium:
		case EBatteryStatus::EBS_Full:
			ControlledCharacter->SetRunSpeed();
			break;
	}
}
