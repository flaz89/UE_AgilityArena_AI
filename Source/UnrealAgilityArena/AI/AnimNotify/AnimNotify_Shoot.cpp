// Fill out your copyright notice in the Description page of Project Settings.


#include "UnrealAgilityArena/AI/AnimNotify/AnimNotify_Shoot.h"

#include "UnrealAgilityArena/AI/BaseDummyCharacter.h"
#include "UnrealAgilityArena/Components/BaseWeaponComponent.h"

UAnimNotify_Shoot::UAnimNotify_Shoot() : Super() 
{
	// enable to set label color to notify in editor
	#if WITH_EDITORONLY_DATA
		NotifyColor = FColor(222, 142, 142, 255);
	#endif
}

void UAnimNotify_Shoot::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation,
	const FAnimNotifyEventReference& EventReference)
{
	if (MeshComp == nullptr) return;
	TObjectPtr<ABaseDummyCharacter> Character = Cast<ABaseDummyCharacter>(MeshComp -> GetOwner());
	
	if (Character == nullptr) return;
	TObjectPtr<UBaseWeaponComponent> WeaponComponent = Character->GetComponentByClass<UBaseWeaponComponent>();
	WeaponComponent->Shoot();
}
