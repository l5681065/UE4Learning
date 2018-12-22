 // Fill out your copyright notice in the Description page of Project Settings.

#include "PuzzlePlatformsGameInstance.h"
#include "Engine/Engine.h"
#include "UObject/ConstructorHelpers.h"
#include "Blueprint/UserWidget.h"
#include "PlatformTrigger.h"

UPuzzlePlatformsGameInstance::UPuzzlePlatformsGameInstance(const FObjectInitializer & ObjectInitializer)
{
	 ConstructorHelpers::FClassFinder<UUserWidget > MenuBPClass(TEXT("/Game/MenuSystem/WBP_MainMenu"));
	 if (!ensure(MenuBPClass.Class != nullptr))
	 {
		 return;
	 }
	 MenuClass = MenuBPClass.Class; 
}

void UPuzzlePlatformsGameInstance::Init()
{
	UE_LOG(LogTemp, Warning, TEXT("Found class %s"), *MenuClass->GetName());
}

void UPuzzlePlatformsGameInstance::LoadMenu()
{
	if (!ensure(MenuClass != nullptr))
	{
		return;
	}
	UUserWidget *Menu=CreateWidget<UUserWidget>(this, MenuClass);
	if (!ensure(Menu != nullptr))
	{
		return;
	}
	Menu->AddToViewport();
	APlayerController *Playercontroller = GetFirstLocalPlayerController();
	if (!ensure(Playercontroller != nullptr))
	{
		return;
	}
	FInputModeUIOnly InputModeData;
	InputModeData.SetWidgetToFocus(Menu->TakeWidget());
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);

	Playercontroller->SetInputMode(InputModeData);
	Playercontroller->bShowMouseCursor=true;

}

void UPuzzlePlatformsGameInstance::Host()
{ 

	UEngine *Engine = GetEngine();
	if (!ensure(Engine!=nullptr))
	{
		return;
	}
	Engine->AddOnScreenDebugMessage(0,2,FColor::Green,TEXT("Hosting"));
	UWorld * World = GetWorld();
	if (!ensure(World!=nullptr))
	{
		return;
	}
	World->ServerTravel("/Game/ThirdPersonCPP/Maps/ThridPersonExampleMap?listen" );
} 

void UPuzzlePlatformsGameInstance::Join(const FString & Address)
{
	UEngine *Engine = GetEngine();
	if (!ensure(Engine != nullptr))
	{
		return;
	}
	Engine->AddOnScreenDebugMessage(0, 2, FColor::Green, FString::Printf(TEXT("Joining %s"), *Address));
	APlayerController *Playercontroller = GetFirstLocalPlayerController();
	if (!ensure(Playercontroller != nullptr))
	{
		return;
	}
	Playercontroller->ClientTravel(Address,ETravelType::TRAVEL_Absolute);


}