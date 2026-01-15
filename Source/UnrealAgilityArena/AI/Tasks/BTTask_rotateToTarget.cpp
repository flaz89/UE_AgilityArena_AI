// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_rotateToTarget.h"

#include "BehaviorTree/BlackboardComponent.h"
#include "UnrealAgilityArena/AI/BaseDummyCharacter.h"
#include "UnrealAgilityArena/AI/AI_Controller/BaseDummyAIController.h"

UBTTask_RotateToTarget::UBTTask_RotateToTarget()
{
	NodeName = "Rotate to target";
	TargetActor.AddObjectFilter(this, GET_MEMBER_NAME_CHECKED(UBTTask_RotateToTarget, TargetActor), AActor::StaticClass());
}

EBTNodeResult::Type UBTTask_RotateToTarget::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	TObjectPtr<ABaseDummyAIController> DummyAIController = Cast<ABaseDummyAIController>(OwnerComp.GetAIOwner());
	if (!DummyAIController) return EBTNodeResult::Failed;
	
	TObjectPtr<UBlackboardComponent> BlackboardComp = OwnerComp.GetBlackboardComponent();
	if (!BlackboardComp) return EBTNodeResult::Failed;
	
	TObjectPtr<ABaseDummyCharacter> DummyCharacter = Cast<ABaseDummyCharacter>(DummyAIController->GetCharacter());
	if (!DummyCharacter) return EBTNodeResult::Failed;
	
	TObjectPtr<AActor> Target = Cast<AActor>(BlackboardComp->GetValueAsObject(TargetActor.SelectedKeyName));
	if (!Target)
	{
		if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Red, TEXT("RotateTask: No target!"));
		return EBTNodeResult::Failed;
	}
	
	FVector Direction = Target->GetActorLocation() - DummyCharacter->GetActorLocation();
	Direction.Z = 0;
	FRotator NewRotation = Direction.Rotation();
	
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Blue, FString::Printf(TEXT("Rotating to %s - Current: %s, New: %s"), 
				*GetNameSafe(Target),
				*DummyCharacter->GetActorRotation().ToString(),
				*NewRotation.ToString())
				);
	
	DummyCharacter->SetActorRotation(NewRotation);
	DummyAIController->SetControlRotation(NewRotation);
	
	return Super::ExecuteTask(OwnerComp, NodeMemory);
}
