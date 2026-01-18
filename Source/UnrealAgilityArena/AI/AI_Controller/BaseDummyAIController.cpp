// Fill out your copyright notice in the Description page of Project Settings.


#include "UnrealAgilityArena/AI/AI_Controller/BaseDummyAIController.h"

#include "BehaviorTree/BlackboardComponent.h"

void ABaseDummyAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	//if BehaviorTree exists (ensureMsgf) execute it
	if (ensureMsgf(BehaviorTree, TEXT("Behavior Three is a nullptr! Please add BehaviorThree in your AI controlller")))
	{
		RunBehaviorTree(BehaviorTree);
		GetPawn()->OnTakeAnyDamage.AddDynamic(this, &ABaseDummyAIController::OnPawnDamaged);
	}
}

void ABaseDummyAIController::OnPawnDamaged(AActor* DamagedActor, float Damage, const UDamageType* DamageType,
	AController* InstigatedBy, AActor* DamageCauser)
{
	const TObjectPtr<UBlackboardComponent> BlackboardComp = GetBlackboardComponent();
	if (BlackboardComp)
	{
		BlackboardComp->SetValueAsBool("IsHit", true);
		if (DamagedActor->Tags.Num() > 0)
		{
			DamagedActor->Tags[0] = "Untagged";
		}
	}
}

