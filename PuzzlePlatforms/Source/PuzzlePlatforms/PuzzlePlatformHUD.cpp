// Fill out your copyright notice in the Description page of Project Settings.

#include "PuzzlePlatformHUD.h"
#include "ConstructorHelpers.h"
#include "UserWidget.h"

void APuzzlePlatformHUD::BeginPlay()
{
	static ConstructorHelpers::FClassFinder<UUserWidget> Inventory(TEXT("/Game/MenuSystem/WBP_Inventory")); 

}
