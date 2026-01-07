// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "BatteryIndicatorComponent.generated.h"

enum class EBatteryStatus : uint8;
/**
 * 
 */
UCLASS(BlueprintType, Blueprintable, ClassGroup="UnrealAgilityArena", meta=(BlueprintSpawnableComponent))
class UNREALAGILITYARENA_API UBatteryIndicatorComponent : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	UBatteryIndicatorComponent();
	
protected:
	UPROPERTY()
	UMaterialInstanceDynamic* DynamicMaterialInstance;
	
	virtual void BeginPlay() override;
	
	UFUNCTION()
	void OnBatteryStatusChange(EBatteryStatus NewStatus);
	
};
