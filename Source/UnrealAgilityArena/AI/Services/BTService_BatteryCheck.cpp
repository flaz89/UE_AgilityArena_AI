// Fill out your copyright notice in the Description page of Project Settings.


#include "UnrealAgilityArena/AI/Services/BTService_BatteryCheck.h"

#include "BehaviorTree/BlackboardComponent.h"
#include "UnrealAgilityArena/AI/BaseDummyCharacter.h"
#include "UnrealAgilityArena/AI/AI_Controller/BaseDummyAIController.h"
#include "UnrealAgilityArena/AI/Utils/BatteryStatus.h"

UBTService_BatteryCheck::UBTService_BatteryCheck()
{
	bCreateNodeInstance = true;
	bNotifyBecomeRelevant = true;
	bNotifyCeaseRelevant = true;
	bNotifyTick = false;
}

void UBTService_BatteryCheck::OnBecomeRelevant(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	// this function is called when node decorated with this service is active
	// check if ai controller exist, check if controlled character exist, if so Controlled character OnBatteryStatusChange delegate is called
	Super::OnBecomeRelevant(OwnerComp, NodeMemory);
	
	BlackboardComp = OwnerComp.GetBlackboardComponent();
	ABaseDummyAIController* AIController = Cast<ABaseDummyAIController>(OwnerComp.GetAIOwner());
	if (!AIController) return;
	// can check if pawn exist
	ControlledCharacter = Cast<ABaseDummyCharacter>(AIController->GetCharacter());
	if (!ControlledCharacter) return;
	
	ControlledCharacter->OnBatteryStatusChanged.AddDynamic(this, &UBTService_BatteryCheck::OnBatteryStatusChange);
}

void UBTService_BatteryCheck::OnCeaseRelevant(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	// this function is called when node decorated with this service is deactivated
	// warns controlled character to remove delegate call
	Super::OnCeaseRelevant(OwnerComp, NodeMemory);
	
	ControlledCharacter->OnBatteryStatusChanged.RemoveDynamic(this, &UBTService_BatteryCheck::OnBatteryStatusChange);
}

void UBTService_BatteryCheck::OnBatteryStatusChange(EBatteryStatus NewBatteryStatus)
{
	// based on battery status, Blackboard boolean keys are updated with value indicating battery capacity
	switch (NewBatteryStatus)
	{
	case EBatteryStatus::EBS_Empty:
		BlackboardComp->SetValueAsBool(IsBatteryDepletedKey.SelectedKeyName, true);
		break;
	case EBatteryStatus::EBS_Low:
		BlackboardComp->SetValueAsBool(IsLowOnBatteryKey.SelectedKeyName, true);
		BlackboardComp->SetValueAsBool(IsBatteryDepletedKey.SelectedKeyName, false);
		break;
	case EBatteryStatus::EBS_Medium:
		break;
	case EBatteryStatus::EBS_Full:
		BlackboardComp->SetValueAsBool(IsLowOnBatteryKey.SelectedKeyName, false);
	}
}



