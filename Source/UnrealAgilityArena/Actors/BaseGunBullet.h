// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EventManager.h"
#include "DataWrappers/ChaosVDParticleDataWrapper.h"
#include "GameFramework/Actor.h"
#include "BaseGunBullet.generated.h"

class UProjectileMovementComponent;
class USphereComponent;

UCLASS(Blueprintable)
class UNREALAGILITYARENA_API ABaseGunBullet : public AActor
{
	GENERATED_BODY()

	
public:	
	// Sets default values for this actor's properties
	ABaseGunBullet();
	USphereComponent* GetCollision() const { return CollisionComponent; }
	UProjectileMovementComponent* GetProjectileMovement() const { return ProjectileMovementComponent; }
	UStaticMeshComponent* GetStaticMesh() const { return MeshComponent; }

protected:
	// Called when the game starts or when spawned
	//virtual void BeginPlay() override;
	
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
	
	UPROPERTY(VisibleDefaultsOnly, Category="Projectile")
	USphereComponent* CollisionComponent;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Projectile", meta=(AllowPrivateAccess=true))
	UStaticMeshComponent* MeshComponent;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Projectile", meta=(AllowPrivateAccess=true))
	UProjectileMovementComponent* ProjectileMovementComponent;
	
	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
