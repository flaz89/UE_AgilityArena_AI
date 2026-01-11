// Fill out your copyright notice in the Description page of Project Settings.


#include "UnrealAgilityArena/Components/BaseWeaponComponent.h"

#include "UnrealAgilityArena/AI/BaseDummyCharacter.h"

UBaseWeaponComponent::UBaseWeaponComponent()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> StaticMeshAsset(TEXT("/Game/KayKit/PrototypeBits/Models/Gun_Pistol.Gun_Pistol"));
	if (StaticMeshAsset.Succeeded()) UStaticMeshComponent::SetStaticMesh(StaticMeshAsset.Object);
}

void UBaseWeaponComponent::Shoot()
{
	if (BulletClass == nullptr) return;

	TObjectPtr<UWorld> const World = GetWorld();
	if (World == nullptr) return;
	
	const FRotator SpawnRotation = GetOwner()->GetActorRotation();
	const FVector SpawnLocation = GetOwner()->GetActorLocation() + SpawnRotation.RotateVector(MuzzleOffset);
	
	FActorSpawnParameters ActorSpawnParams;
	ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;
	
	World->SpawnActor<AActor>(BulletClass, SpawnLocation, SpawnRotation, ActorSpawnParams);
	
	
}

void UBaseWeaponComponent::BeginPlay()
{
	Super::BeginPlay();
	
	const TObjectPtr<ABaseDummyCharacter> Character = Cast<ABaseDummyCharacter>(GetOwner());
	if (Character == nullptr) return;
	AttachToComponent(Character->GetMesh(), FAttachmentTransformRules::SnapToTargetIncludingScale, "hand_right");
}
