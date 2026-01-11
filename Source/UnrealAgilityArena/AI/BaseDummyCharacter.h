// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Utils/BatteryStatus.h"
#include "BaseDummyCharacter.generated.h"

//enum class EBatteryStatus : uint8;

UCLASS()
class UNREALAGILITYARENA_API ABaseDummyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABaseDummyCharacter();
	virtual void Tick(float DeltaTime) override;
	
	UFUNCTION(BlueprintCallable, Category="Character Movement")
	void SetWalkSpeed();
	UFUNCTION(BlueprintCallable, Category="Character Movement")
	void SetRunSpeed();
	UFUNCTION(BlueprintCallable, BlueprintGetter, Category="Character Battery")
	EBatteryStatus GetBatteryStatus() const;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Character Battery")
	float MaxBatteryLevel = 100.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Character Battery")
	float BatteryCostPerTick = 5.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Character Battery")
	float BatteryRechargePerTick = 1.f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Character Movement")
	float RunSpeed = 650.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Character Movement")
	float WalkSpeed = 500.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Character Movement")
	float MovementRandomDeviation = 5.f;
	
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnBatteryStatusChanged, EBatteryStatus, NewBatteryStatus);
	
	UPROPERTY(BlueprintAssignable, Category="Character Battery")
	FOnBatteryStatusChanged OnBatteryStatusChanged;

	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UPROPERTY()
	float BatteryLevel {};

};
