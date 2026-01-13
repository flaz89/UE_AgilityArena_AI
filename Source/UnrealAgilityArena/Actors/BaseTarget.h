// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseTarget.generated.h"

UCLASS()
class UNREALAGILITYARENA_API ABaseTarget : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ABaseTarget();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Target", meta=(AllowPrivateAccess=true))
	TObjectPtr<UStaticMeshComponent> MeshComponent;
	
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;
};
