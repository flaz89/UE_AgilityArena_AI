// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseNoiseEmitter.h"

#include "Components/StateTreeComponent.h"
#include "Perception/AIPerceptionStimuliSourceComponent.h"
#include "Perception/AISense_Hearing.h"


// Sets default values
ABaseNoiseEmitter::ABaseNoiseEmitter()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	
	BaseMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	RootComponent = BaseMeshComponent;
	static ConstructorHelpers::FObjectFinder<UStaticMesh> BaseStaticMeshAsset(TEXT("/Game/KayKit/SpaceBase/landingpad_large.landingpad_large"));
	if (BaseStaticMeshAsset.Succeeded())
	{
		BaseMeshComponent->SetStaticMesh(BaseStaticMeshAsset.Object);
	}
	
	DummyMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DummyMesh"));
	DummyMeshComponent->SetupAttachment(BaseMeshComponent);
	DummyMeshComponent->SetRelativeRotation(FRotator(0.0f, -90.0f, 0.0f));
	DummyMeshComponent->SetRelativeLocation(FVector(0.0f, 0.0f, 80.0f));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> DummyStaticMeshAsset(TEXT("/Game/KayKit/PrototypeBits/Models/Dummy_Base.Dummy_Base"));
	if (DummyStaticMeshAsset.Succeeded())
	{
		DummyMeshComponent->SetStaticMesh(DummyStaticMeshAsset.Object);
	}
	
	PerceptionStimuliSourceComponent = CreateDefaultSubobject<UAIPerceptionStimuliSourceComponent>(TEXT("PerceptionStimuliSource"));
	PerceptionStimuliSourceComponent->RegisterForSense(UAISense_Hearing::StaticClass());
	
	StateTreeComponent = CreateDefaultSubobject<UStateTreeComponent>(TEXT("StateTree"));
}

void ABaseNoiseEmitter::EmitNoise()
{
	const float NoiseRange = MaxNoiseRange + FMath::RandRange(-1.f * NoiseRangeRandomDeviation, NoiseRangeRandomDeviation);
	UAISense_Hearing::ReportNoiseEvent(GetWorld(), GetActorLocation(), 1.f, this, MaxNoiseRange, NoiseTag);
}

// Called when the game starts or when spawned
void ABaseNoiseEmitter::BeginPlay()
{
	Super::BeginPlay();
	PerceptionStimuliSourceComponent->RegisterWithPerceptionSystem();
	StateTreeComponent->StartLogic();
}

