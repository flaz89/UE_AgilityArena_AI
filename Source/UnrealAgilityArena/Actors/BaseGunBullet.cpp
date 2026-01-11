// Fill out your copyright notice in the Description page of Project Settings.


#include "UnrealAgilityArena/Actors/BaseGunBullet.h"

#include "Components/SphereComponent.h"
#include "Engine/DamageEvents.h"
#include "GameFramework/ProjectileMovementComponent.h"

// Sets default values
ABaseGunBullet::ABaseGunBullet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	
	InitialLifeSpan = 10.0f;
	
	CollisionComponent = CreateDefaultSubobject<USphereComponent>(FName("Collision"));
	CollisionComponent->InitSphereRadius(20.f);
	CollisionComponent->BodyInstance.SetCollisionProfileName("BlockAll");
	CollisionComponent->OnComponentHit.AddDynamic(this, &ABaseGunBullet::OnHit);
	CollisionComponent->SetWalkableSlopeOverride(FWalkableSlopeOverride(WalkableSlope_Unwalkable, 0.f));
	CollisionComponent->CanCharacterStepUpOn = ECB_No;
	RootComponent = CollisionComponent;
	
	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(FName("Projectile"));
	ProjectileMovementComponent->UpdatedComponent = CollisionComponent;
	ProjectileMovementComponent->InitialSpeed = 1800.f;
	ProjectileMovementComponent->MaxSpeed = 1800.f;
	ProjectileMovementComponent->bRotationFollowsVelocity = true;
	ProjectileMovementComponent->ProjectileGravityScale = 0.f;
	
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(FName("Mesh"));
	MeshComponent->SetupAttachment(RootComponent);
	MeshComponent->SetRelativeRotation(FRotator(0.0f, -90.0f, 0.0f));
	MeshComponent->SetRelativeScale3D(FVector(2.0f, 2.0f, 2.0f));
	
	static ConstructorHelpers::FObjectFinder<UStaticMesh> StaticMeshAsset(TEXT("/Game/KayKit/PrototypeBits/Models/Bullet.Bullet"));
	if (StaticMeshAsset.Succeeded()) MeshComponent -> SetStaticMesh(StaticMeshAsset.Object);

}

void ABaseGunBullet::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	FVector NormalImpulse, const FHitResult& Hit)
{
	if (OtherActor != nullptr && OtherActor != this)
	{
		const FDamageEvent DamageEvent = FDamageEvent();
		OtherActor->TakeDamage(1.f, DamageEvent, nullptr, nullptr);
	}
	Destroy();
}

// Called when the game starts or when spawned
/*void ABaseGunBullet::BeginPlay()
{
	Super::BeginPlay();
	
}*/

// Called every frame
void ABaseGunBullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

