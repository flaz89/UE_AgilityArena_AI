// Fill out your copyright notice in the Description page of Project Settings.


#include "UnrealAgilityArena/AI/BatteryIndicatorComponent.h"

#include "BaseDummyCharacter.h"


UBatteryIndicatorComponent::UBatteryIndicatorComponent()
{
	// load Static static mesh geometry straight at construction with specified geometry
	static ConstructorHelpers::FObjectFinder<UStaticMesh> StaticMeshAsset(TEXT("/Game/_GENERATED/MarcoSecchi/SM_HeadLight.SM_Headlight"));
	if (StaticMeshAsset.Succeeded()) UStaticMeshComponent::SetStaticMesh(StaticMeshAsset.Object);
}

void UBatteryIndicatorComponent::BeginPlay()
{
	Super::BeginPlay();
	ABaseDummyCharacter* Owner = Cast<ABaseDummyCharacter>(GetOwner());
	if (Owner == nullptr) return;
	
	//if (Owner->GetMesh()->GetSocketByName("helmet")) UE_LOG(LogTemp, Warning, TEXT("Helmet socket is present"));
	AttachToComponent(Owner->GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, TEXT("helmet"));
	
	DynamicMaterialInstance = this -> CreateDynamicMaterialInstance(1, GetMaterial(1));
	Owner->OnBatteryStatusChanged.AddDynamic(this, &UBatteryIndicatorComponent::OnBatteryStatusChange);
	
	
}

void UBatteryIndicatorComponent::OnBatteryStatusChange(EBatteryStatus NewStatus)
{
	const float BatteryValue = StaticCast<float>(NewStatus);
	const float Intensity = (BatteryValue -1) * .25f;
	DynamicMaterialInstance->SetScalarParameterValue("Intensity", Intensity);
}
