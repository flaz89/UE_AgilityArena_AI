// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimNotify_Shoot.h"

#include "UnrealAgilityArena/AI/BaseDummyCharacter.h"
#include "UnrealAgilityArena/Components/BaseWeaponComponent.h"

UAnimNotify_Shoot::UAnimNotify_Shoot()
{
	// preprocessor directive to avoid compilation failure in packaged project
	#if WITH_EDITORONLY_DATA
		NotifyColor = FColor(222, 142, 142, 255);
	#endif
}

void UAnimNotify_Shoot::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation,
	const FAnimNotifyEventReference& EventReference)
{
	// check if the owner is BaseDummyCharacter, if so check if exist the WeaponComponent and call Shoot() function from WeaponComponent
	TObjectPtr<ABaseDummyCharacter> GunnerCharacter = Cast<ABaseDummyCharacter>(MeshComp->GetOwner());
	if (!GunnerCharacter) return;

	if (const TObjectPtr<UBaseWeaponComponent> WeaponComponent = GunnerCharacter->GetComponentByClass<UBaseWeaponComponent>()) 
		WeaponComponent -> Shoot();
}
