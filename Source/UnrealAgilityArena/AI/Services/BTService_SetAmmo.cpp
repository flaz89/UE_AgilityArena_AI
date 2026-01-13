// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_SetAmmo.h"

#include "BehaviorTree/BlackboardComponent.h"

UBTService_SetAmmo::UBTService_SetAmmo()
{
	NodeName = "SetAmmo";
	bCreateNodeInstance = true; // crate single instance for each AI
	bNotifyBecomeRelevant = true; // call callback function OnBecomeRelevant()
	bNotifyTick = false; // deactivate TickNode()
}

void UBTService_SetAmmo::OnBecomeRelevant(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	const TObjectPtr<UBlackboardComponent> BlackboardComp = OwnerComp.GetBlackboardComponent();
	if (BlackboardComp) BlackboardComp->SetValueAsBool(NeedsReload.SelectedKeyName, bKeyValue);
}
