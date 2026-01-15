// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseWeaponComponent.h"

#include "UnrealAgilityArena/AI/BaseDummyCharacter.h"

UBaseWeaponComponent::UBaseWeaponComponent()
{
	// if hardcoded static mesh exists, loads geometry automatically 
	static ConstructorHelpers::FObjectFinder<UStaticMesh> StaticMeshAsset(TEXT("/Game/KayKit/PrototypeBits/Models/Gun_Pistol.Gun_Pistol"));
	if (StaticMeshAsset.Succeeded()) UBaseWeaponComponent::SetStaticMesh(StaticMeshAsset.Object);
}

void UBaseWeaponComponent::Shoot()
{
	// check if bullet class has been set and if level exists
	if (BulletClass && GetWorld())
	{
		// obtain rotation and location from the owner (Character), set collision parameters and spawn actor using data
		const FRotator SpawnRotation = GetOwner()->GetActorRotation();
		const FVector SpawnLocation = GetOwner()->GetActorLocation() + SpawnRotation.RotateVector(MuzzleOffset);
		
		FActorSpawnParameters BulletSpawnParams;
		BulletSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;
		
		BulletSpawnParams.Owner = GetOwner();               
		BulletSpawnParams.Instigator = Cast<APawn>(GetOwner());
		
		GetWorld()->SpawnActor<AActor>(BulletClass, SpawnLocation, SpawnRotation, BulletSpawnParams);
	}
}

void UBaseWeaponComponent::BeginPlay()
{
	Super::BeginPlay();
	
	// at begin play check if the owner is a "BaseDummyCharacter" class, if so, get the owner mesh and attach itself to specific socket
	const ABaseDummyCharacter* Character = Cast<ABaseDummyCharacter>(GetOwner());
	if (Character) AttachToComponent(Character->GetMesh(), FAttachmentTransformRules::SnapToTargetIncludingScale, "hand_right");
}
