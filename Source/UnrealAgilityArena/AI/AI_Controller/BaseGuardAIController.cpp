// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseGuardAIController.h"

#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Hearing.h"


// Sets default values
ABaseGuardAIController::ABaseGuardAIController()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	
	UAISenseConfig_Hearing* SenseConfig_Hearing = CreateDefaultSubobject<UAISenseConfig_Hearing>(FName("SenseConfig_Hearing"));
	SenseConfig_Hearing->DetectionByAffiliation.bDetectEnemies = true;
	SenseConfig_Hearing->DetectionByAffiliation.bDetectFriendlies = true;
	SenseConfig_Hearing->DetectionByAffiliation.bDetectNeutrals = true;
	SenseConfig_Hearing->HearingRange = 2500.f;
	SenseConfig_Hearing->SetStartsEnabled(true);
	
	PerceptionComponent = CreateDefaultSubobject<UAIPerceptionComponent>(FName("Perception"));
	PerceptionComponent->ConfigureSense(*SenseConfig_Hearing);
	PerceptionComponent->SetDominantSense(SenseConfig_Hearing->GetSenseImplementation());
	PerceptionComponent->OnTargetPerceptionUpdated.AddDynamic(this, &ABaseGuardAIController::OnTargetPerceptionUpdated);
}

// Called when the game starts or when spawned
void ABaseGuardAIController::BeginPlay()
{
	Super::BeginPlay();
	
}


