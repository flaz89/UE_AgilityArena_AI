// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseSecurityCamAIController.h"

#include "Perception/AIPerceptionComponent.h"
#include "Perception/AIPerceptionTypes.h"
#include "Perception/AISenseConfig_Sight.h"


// Sets default values
ABaseSecurityCamAIController::ABaseSecurityCamAIController()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	
	const TObjectPtr<UAISenseConfig_Sight> SenseConfig_Sight = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("SenseConfoig_Sight"));
	SenseConfig_Sight->SightRadius = 1600.f;
	SenseConfig_Sight->LoseSightRadius = 3000.f;
	SenseConfig_Sight->PeripheralVisionAngleDegrees = 45.f;
	SenseConfig_Sight->DetectionByAffiliation.bDetectEnemies = true;
	SenseConfig_Sight->DetectionByAffiliation.bDetectNeutrals = true;
	SenseConfig_Sight->DetectionByAffiliation.bDetectFriendlies = true;
	
	PerceptionComponent = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("Perception"));
	PerceptionComponent->ConfigureSense(*SenseConfig_Sight);
	PerceptionComponent->SetDominantSense(SenseConfig_Sight->GetSenseImplementation());
	PerceptionComponent->OnTargetPerceptionUpdated.AddDynamic(this, &ABaseSecurityCamAIController::OnTargetPerceptionUpdate);
}

// Called when the game starts or when spawned
void ABaseSecurityCamAIController::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABaseSecurityCamAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	if (ensureMsgf(UBehaviorTree, TEXT("Bheavior Tree in nullptr! Please assign BehaviorTree in your AI Controller")))
	{
		RunBehaviorTree(UBehaviorTree);
	}
}

void ABaseSecurityCamAIController::OnTargetPerceptionUpdate(AActor* Actor, FAIStimulus Stimulus)
{
	if (Actor->Tags.Num() > 0 ) return;
	
	const FAISenseID SightID = UAISense::GetSenseID<UAISense_Sight>();
	if (Stimulus.Type == SightID && Stimulus.WasSuccessfullySensed())
	{
		Actor->Tags.Init({}, 1);
		Actor->Tags[0] = "ShootingTarget";
	}
}

