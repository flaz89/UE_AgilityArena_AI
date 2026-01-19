// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseNoiseEmitter.generated.h"

class UStateTreeComponent;
class UAIPerceptionStimuliSourceComponent;

UCLASS(Blueprintable)
class UNREALAGILITYARENA_API ABaseNoiseEmitter : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ABaseNoiseEmitter();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Noise Generation")
	float MaxNoiseRange = 3000.f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Noise Generation")
	float NoiseRangeRandomDeviation = 100.f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Noise Generation")
	FName NoiseTag = "EmitterNoise";
	
	UFUNCTION(BlueprintCallable)
	void EmitNoise();
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
private:
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Dummy Target", meta=(AllowPrivateAccess = true))
	TObjectPtr<UStaticMeshComponent> BaseMeshComponent;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Dummy Target", meta=(AllowPrivateAccess = true))
	TObjectPtr<UStaticMeshComponent> DummyMeshComponent;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Dummy Target", meta=(AllowPrivateAccess = true))
	TObjectPtr<UAIPerceptionStimuliSourceComponent> PerceptionStimuliSourceComponent;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Dummy Target", meta=(AllowPrivateAccess = true))
	TObjectPtr<UStateTreeComponent> StateTreeComponent;
};
