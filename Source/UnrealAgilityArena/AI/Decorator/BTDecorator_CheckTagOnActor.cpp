// Fill out your copyright notice in the Description page of Project Settings.


#include "BTDecorator_CheckTagOnActor.h"

#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Object.h"

UBTDecorator_CheckTagOnActor::UBTDecorator_CheckTagOnActor()
{
	NodeName = "Tag Condition";
	ActorToCheck.AddObjectFilter(this, GET_MEMBER_NAME_CHECKED(UBTDecorator_CheckTagOnActor, ActorToCheck), AActor::StaticClass());
	ActorToCheck.SelectedKeyName = FBlackboard::KeySelf;
}

bool UBTDecorator_CheckTagOnActor::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp,
	uint8* NodeMemory) const
{
	// Get the Blackboard containing this decorator
	const TObjectPtr<UBlackboardComponent> BlackboardComponent = OwnerComp.GetBlackboardComponent();
	if (!BlackboardComponent) return false;
	
	// return true if the variable of type AActor stored in Blackboard has a tag corresponding to TagName
	const TObjectPtr<AActor> Actor = Cast<AActor>(BlackboardComponent->GetValue<UBlackboardKeyType_Object>(ActorToCheck.SelectedKeyName));
	return Actor != nullptr && Actor->ActorHasTag(TagName);
}

void UBTDecorator_CheckTagOnActor::InitializeFromAsset(UBehaviorTree& Asset)
{
	Super::InitializeFromAsset(Asset);
	
	if (const TObjectPtr<UBlackboardData> BBAsset = GetBlackboardAsset(); ensure(BBAsset))
	{
		ActorToCheck.ResolveSelectedKey(*BBAsset);
	}
}
