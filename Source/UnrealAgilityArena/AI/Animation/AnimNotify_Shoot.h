// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "AnimNotify_Shoot.generated.h"

/**
 * 
 */
UCLASS(const, HideCategories=Object, CollapseCategories, Config=Game, meta=(DisplayName="Shoot"))
class UNREALAGILITYARENA_API UAnimNotify_Shoot : public UAnimNotify
{
	GENERATED_BODY()
	
public:
	UAnimNotify_Shoot();
	
	virtual void Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference) override;
	
};
