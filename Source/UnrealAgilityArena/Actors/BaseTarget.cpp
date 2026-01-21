// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseTarget.h"


// Sets default values
ABaseTarget::ABaseTarget()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	MeshComponent->SetRelativeRotation(FRotator(0.0f, -90.0f, 0.0f));
	
	static ConstructorHelpers::FObjectFinder<UStaticMesh> StaticMeshAsset(TEXT("/Game/KayKit/PrototypeBits/Models/target_stand_B_target_stand_B.target_stand_B_target_stand_B"));
	if (StaticMeshAsset.Succeeded()) MeshComponent->SetStaticMesh(StaticMeshAsset.Object);
}

float ABaseTarget::TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent,
	class AController* EventInstigator, AActor* DamageCauser)
{
	
	Tags[0] = "Untagged";
	Destroy();
	return DamageAmount;
}



