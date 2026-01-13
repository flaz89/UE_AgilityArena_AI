// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_PlayMontage.h"

#include "UnrealAgilityArena/AI/BaseDummyCharacter.h"
#include "UnrealAgilityArena/AI/AI_Controller/BaseDummyAIController.h"

UBTTask_PlayMontage::UBTTask_PlayMontage()
{
}

EBTNodeResult::Type UBTTask_PlayMontage::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	// check if animMontage exists
	if (ShootAnimMontage == nullptr) return EBTNodeResult::Failed;
	
	// check if an AIController exists
	const TObjectPtr<ABaseDummyAIController> AIController = Cast<ABaseDummyAIController>(OwnerComp.GetAIOwner());
	if (AIController == nullptr) return EBTNodeResult::Failed;
	
	// if AIController exists, extract character
	const TObjectPtr<ABaseDummyCharacter> Character = Cast<ABaseDummyCharacter>(AIController->GetCharacter());
	if (Character == nullptr) return EBTNodeResult::Failed;
	//if character exist so play AnimMontage with AnimMontage passed by pointer
	Character->PlayAnimMontage(ShootAnimMontage);
	 
	return EBTNodeResult::Succeeded;
}
