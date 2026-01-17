// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseSecurityCam.h"


// Sets default values
ABaseSecurityCam::ABaseSecurityCam()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	
	SupportMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SupportMesh"));
	RootComponent = SupportMeshComponent;
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SupportStaticMesh(TEXT("/Game/_GENERATED/MarcoSecchi/SM_SecurityCam_Base.SM_SecurityCam_Base"));
	if (SupportStaticMesh.Succeeded()) SupportMeshComponent->SetStaticMesh(SupportStaticMesh.Object);
	
	SecurityCamComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SecurityCam"));
	SecurityCamComponent->SetRelativeLocation(FVector(61.0f, 0.0f, -13.f));
	SecurityCamComponent->SetupAttachment(SupportMeshComponent);
	static ConstructorHelpers::FObjectFinder<UStaticMesh> CameraStaticMesh(TEXT("/Game/_GENERATED/MarcoSecchi/SM_SecurityCam.SM_SecurityCam"));
	if (CameraStaticMesh.Succeeded()) SecurityCamComponent->SetStaticMesh(CameraStaticMesh.Object);
	
}


// Called to bind functionality to input
void ABaseSecurityCam::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

