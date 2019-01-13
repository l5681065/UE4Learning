 // Fill out your copyright notice in the Description page of Project Settings.

#include "PuzzlePlatformsGameInstance.h"
#include "Engine/Engine.h"
#include "UObject/ConstructorHelpers.h"
#include "Blueprint/UserWidget.h"
#include "PlatformTrigger.h"
#include "MenuSystem/MainMenu.h"
#include "MenuSystem/InGameMenu.h"
#include "OnlineSubsystem.h"

UPuzzlePlatformsGameInstance::UPuzzlePlatformsGameInstance(const FObjectInitializer & ObjectInitializer)
{
	 ConstructorHelpers::FClassFinder<UUserWidget > MenuBPClass(TEXT("/Game/MenuSystem/WBP_MainMenu"));
	 if (!ensure(MenuBPClass.Class != nullptr))
	 {
		 return;
	 }
	 MenuClass = MenuBPClass.Class; 
	 ConstructorHelpers::FClassFinder<UUserWidget >  InGameMenuBPClass(TEXT("/Game/MenuSystem/WBP_InGameMenu"));
	 if (!ensure(InGameMenuBPClass.Class != nullptr))
	 {
		 return;
	 }
	 InGameMenuClass = InGameMenuBPClass.Class;
}

void UPuzzlePlatformsGameInstance::Init()
{
	IOnlineSubsystem * Subsystem = IOnlineSubsystem::Get();
	if (Subsystem!=nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Found class %s"), *Subsystem->GetSubsystemName().ToString());
		IOnlineSessionPtr SessionInterface= Subsystem->GetSessionInterface();
	if (SessionInterface.IsValid())
	{
		UE_LOG(LogTemp, Warning, TEXT("Found SessionInterface"));
	}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Found no Subsystem "));
	}
	//UE_LOG(LogTemp, Warning, TEXT("Found class %s"), *MenuClass->GetName());
}

void UPuzzlePlatformsGameInstance::LoadMenuWidget()
{
	if (!ensure(MenuClass != nullptr))
	{
		return;
	}
   Menu=CreateWidget<UMainMenu>(this, MenuClass);
	if (!ensure(Menu != nullptr)) 
	{
		return;
	}
	Menu->Setup();
	Menu->SetMenuInterface(this);

}

void UPuzzlePlatformsGameInstance::InGameLoadMenu()
{
	UEngine *Engine = GetEngine();
	if (!ensure(InGameMenuClass != nullptr))
	{
		return;
	}
	InGameMenu = CreateWidget<UInGameMenu>(this, InGameMenuClass);
	if (!ensure(InGameMenu != nullptr))
	{
		return;
	}
	InGameMenu->Setup();
	InGameMenu->SetMenuInterface(this);
}

void UPuzzlePlatformsGameInstance::Host()
{ 
	if (Menu!=nullptr)
	{
		Menu->Teardown();
	}

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
	if (Menu != nullptr)
	{
		Menu->Teardown();
	}

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

void UPuzzlePlatformsGameInstance::Foobar()
{

}

void UPuzzlePlatformsGameInstance::LoadMainMenu()
{
	APlayerController *Playercontroller = GetFirstLocalPlayerController();
	if (!ensure(Playercontroller != nullptr))
	{
		return;
	}
	Playercontroller->ClientTravel("/Game/MenuSystem/MainMenu", ETravelType::TRAVEL_Absolute);
}
