// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseGunBullet.generated.h"

class UProjectileMovementComponent;
class USphereComponent;

UCLASS(Blueprintable)
class UNREALAGILITYARENA_API ABaseGunBullet : public AActor
{
	GENERATED_BODY()

public:
	ABaseGunBullet();
	
	virtual void Tick(float DeltaTime) override;
	
	// getters
	USphereComponent* GetCollision() const { return  CollisionComponent; }
	UStaticMeshComponent* GetMesh() const { return  MeshComponent; }
	UProjectileMovementComponent* GetProjectileMovement() const { return ProjectileMovementComponent; }

protected:
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
	
	UPROPERTY(VisibleDefaultsOnly, Category="Projectile")
	TObjectPtr<USphereComponent> CollisionComponent;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Projectile", meta=(AllowPrivateAccess="true"))
	TObjectPtr<UStaticMeshComponent> MeshComponent;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Movement", meta=(AllowPrivateAccess="true"))
	TObjectPtr<UProjectileMovementComponent> ProjectileMovementComponent;
};
