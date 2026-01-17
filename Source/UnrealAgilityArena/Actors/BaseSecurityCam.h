// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BaseSecurityCam.generated.h"

UCLASS(Blueprintable)
class UNREALAGILITYARENA_API ABaseSecurityCam : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABaseSecurityCam();
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Security Cam")
	TObjectPtr<UStaticMeshComponent> SupportMeshComponent;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Security Cam")
	TObjectPtr<UStaticMeshComponent> SecurityCamComponent;
};
 