// Fill out your copyright notice in the Description page of Project Settings.

#include "PuzzlePlatformHUD.h"
#include "ConstructorHelpers.h"
#include "UserWidget.h"

APuzzlePlatformHUD::APuzzlePlatformHUD()
{
	static ConstructorHelpers::FClassFinder<UUserWidget> W_CompoundImage(TEXT("/Game/W_compoundImage"));
	WBP_CompoundImage = W_CompoundImage.Class;
}

void APuzzlePlatformHUD::BeginPlay()
{
	Super::BeginPlay();	
	CreateWidget(GetWorld(), WBP_CompoundImage)->AddToViewport();
}
