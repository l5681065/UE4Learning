// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "PuzzlePlatformHUD.generated.h"

/**
 * 
 */
UCLASS()
class PUZZLEPLATFORMS_API APuzzlePlatformHUD : public AHUD
{
	GENERATED_BODY()
public:
	APuzzlePlatformHUD();

	TSubclassOf<UUserWidget> WBP_CompoundImage;
protected:
		virtual void BeginPlay() override;

	
};
