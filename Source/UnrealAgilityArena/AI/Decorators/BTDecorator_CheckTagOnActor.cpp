// Fill out your copyright notice in the Description page of Project Settings.


#include "UnrealAgilityArena/AI/Decorators/BTDecorator_CheckTagOnActor.h"

#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Object.h"

UBTDecorator_CheckTagOnActor::UBTDecorator_CheckTagOnActor()
{
	// naming the node and filtering kew value to allowed Actor classes. 
	NodeName = "Tag Condition";
	ActorToCheck.AddObjectFilter(this, GET_MEMBER_NAME_CHECKED(UBTDecorator_CheckTagOnActor, ActorToCheck), AActor::StaticClass() );
	ActorToCheck.SelectedKeyName = FBlackboard::KeySelf;
}

bool UBTDecorator_CheckTagOnActor::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp,
                                                              uint8* NodeMemory) const
{
	const TObjectPtr<UBlackboardComponent> BlackboardComp = OwnerComp.GetBlackboardComponent();
	if (BlackboardComp == nullptr) return false;
	
	const TObjectPtr<AActor> Actor = Cast<AActor>(BlackboardComp-> GetValue<UBlackboardKeyType_Object>(ActorToCheck.SelectedKeyName));
	
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
