// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_PlayMontage.h"

#include "AIController.h"
#include "GameFramework/Character.h"

UBTTask_PlayMontage::UBTTask_PlayMontage()
{
}

EBTNodeResult::Type UBTTask_PlayMontage::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	if (AnimMontage == nullptr) return EBTNodeResult::Failed;
	
	const TObjectPtr<AAIController> Controller = OwnerComp.GetAIOwner();
	if (Controller == nullptr) return EBTNodeResult::Failed;
	
	const TObjectPtr<ACharacter> Character = Cast<ACharacter>(Controller->GetCharacter());
	if (Character == nullptr) return EBTNodeResult::Failed;
	Character->PlayAnimMontage(AnimMontage, 1.f, FName("Default"));
	return EBTNodeResult::Succeeded;
}
