// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseDummyCharacter.h"

#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"


// Sets default values
ABaseDummyCharacter::ABaseDummyCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.TickInterval = 0.25f;
	
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationPitch = false;
	
	// Set Skeletal mesh
	GetMesh()->SetRelativeLocation(FVector(0.0f, 0.0f, -120.f));
	GetMesh()->SetRelativeRotation(FRotator(0.0f, -90.f, 0.0f));
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> SkeletalMeshAsset(TEXT("/Game/KayKit/PrototypeBits/Character/Dummy.Dummy"));
	if (SkeletalMeshAsset.Succeeded()) GetMesh()->SetSkeletalMesh(SkeletalMeshAsset.Object);
	
	// Set ABP with SetAnimInstanceClass pointing to Runtime Class wit suffix_C on path
	GetMesh()->SetAnimationMode(EAnimationMode::Type::AnimationBlueprint);
	static ConstructorHelpers::FClassFinder<UAnimInstance> AnimInstanceBP(TEXT("/Game/KayKit/PrototypeBits/Character/ABP_Dummy.ABP_Dummy_C"));
	if (AnimInstanceBP.Succeeded()) GetMesh()->SetAnimInstanceClass(AnimInstanceBP.Class);
	
	//Set Capsule component
	GetCapsuleComponent()-> InitCapsuleSize(50.f, 120.f);
	
	//Set Character Movement component
	GetCharacterMovement() -> bOrientRotationToMovement = true;
	GetCharacterMovement() -> MaxWalkSpeed = 500.f;
	GetCharacterMovement() -> RotationRate = FRotator(0.0f, 640.0f, 0.0f);
	GetCharacterMovement() -> bConstrainToPlane = true;
	GetCharacterMovement() -> bSnapToPlaneAtStart = true;
	GetCharacterMovement() -> AvoidanceConsiderationRadius = 2000.f;
	GetCharacterMovement() -> bUseRVOAvoidance = true;
}

void ABaseDummyCharacter::BeginPlay()
{
	Super::BeginPlay();
	// Set BatteryLevel with random value and call delegate (dispatch event)
	BatteryLevel = FMath::RandRange(0.f, MaxBatteryLevel);
	OnBatteryStatusChanged.Broadcast(GetBatteryStatus());
	
	// Print Debug
	float Level = BatteryLevel / MaxBatteryLevel;
	UE_LOG(LogTemp, Warning, TEXT("BatteryLevel: %f"), BatteryLevel);
	UE_LOG(LogTemp, Warning, TEXT("BatteryLevel / MaxBatteryLevel: %f"), Level);
	UE_LOG(LogTemp, Warning, TEXT("BatteryLevel: %d"), GetBatteryStatus());
}

// Called every frame
void ABaseDummyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	// check BatteryLevel and update BatteryStatus with delegate (dispatch event)
	const EBatteryStatus CurrentStatus = GetBatteryStatus();
	if (GetMovementComponent() -> Velocity.Size() > 0.1f)
	{
		BatteryLevel -= BatteryCostPerTick;
	} else
	{
		BatteryLevel += BatteryRechargePerTick;
	}
	BatteryLevel = FMath::Clamp(BatteryLevel, 0.f, MaxBatteryLevel);
	if (const EBatteryStatus NewStatus = GetBatteryStatus(); CurrentStatus != NewStatus)
	{
		OnBatteryStatusChanged.Broadcast(NewStatus);
	}
	
	if (GEngine) GEngine -> AddOnScreenDebugMessage(-1, 0.25f, FColor::White, FString::Printf(TEXT("Battery Status: %d"), GetBatteryStatus()));
}

/*
  *Set MaxWalkSpeed of CharacterMovementComponent 
*/
void ABaseDummyCharacter::SetWalkSpeed()
{
	const float Deviation = FMath::RandRange(-1.f * MovementRandomDeviation, MovementRandomDeviation);
	GetCharacterMovement() -> MaxWalkSpeed = WalkSpeed + Deviation;
}

void ABaseDummyCharacter::SetRunSpeed()
{
	const float Deviation = FMath::RandRange(-1.f * MovementRandomDeviation, MovementRandomDeviation);
	GetCharacterMovement() -> MaxWalkSpeed = RunSpeed + Deviation;
}

EBatteryStatus ABaseDummyCharacter::GetBatteryStatus() const
{
	const float Level = BatteryLevel / MaxBatteryLevel;
	if (Level < 0.05) return EBatteryStatus::EBS_Empty;
	if (Level < 0.35) return EBatteryStatus::EBS_Low;
	if (Level < 0.95) return EBatteryStatus::EBS_Medium;
	
	return EBatteryStatus::EBS_Full;
}

