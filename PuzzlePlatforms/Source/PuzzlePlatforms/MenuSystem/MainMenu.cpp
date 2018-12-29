// Fill out your copyright notice in the Description page of Project Settings.

#include "MainMenu.h"
#include "Components/Button.h"
#include "Components/WidgetSwitcher.h"
#include "Components/EditableTextBox.h"



bool UMainMenu::Initialize()
{
	 bool Success=	Super::Initialize();
	 if (!Success)
	 {
		 return false;
	 }
	 if (!ensure(HostButton != nullptr))
	 {
		 return false;
	 }
	 HostButton->OnClicked.AddDynamic(this,&UMainMenu::HostServer);
	 if (!ensure(JoinButton != nullptr))
	 {
		 return false;
	 }
	 JoinButton->OnClicked.AddDynamic(this, &UMainMenu::OpenJoinMenu);

	 if (!ensure(CancelJoinButton != nullptr))
	 {
		 return false;
	 }
	 CancelJoinButton->OnClicked.AddDynamic(this, &UMainMenu::OpenMainMenu);
	 if (!ensure(ConfirmJoinButton != nullptr))
	 {
		 return false;
	 }
	 ConfirmJoinButton->OnClicked.AddDynamic(this,&UMainMenu::JoinServer);
	 if (!ensure(QuitButton != nullptr))
	 {
		 return false;
	 }
	 QuitButton->OnClicked.AddDynamic(this, &UMainMenu::QuitPressed);
	 return true;
}

void UMainMenu::NativeConstruct()
{
	Super::NativeConstruct();
	GEngine->AddOnScreenDebugMessage(0, 2000, FColor::Green, " NavtivesConstruct!!");
}

void UMainMenu::Construct()
{
	Super::Construct();
	GEngine->AddOnScreenDebugMessage(1,2000,FColor::Green," Construct!");
}

void UMainMenu::HostServer()
{
	if (MenuInterface!=nullptr)
	{
		MenuInterface->Host();
	}
}

void UMainMenu::OpenMainMenu()
{
	if (!ensure(MenuSwitcher != nullptr))
	{
		return;
	}
	if (!ensure( MainMenu!= nullptr))
	{
		return;
	}
	MenuSwitcher->SetActiveWidget(MainMenu);
}

void UMainMenu::QuitPressed()
{
	UWorld *World = GetWorld();
	if (!ensure(World != nullptr))
	{
		return;
	}

	APlayerController *Playercontroller = World->GetFirstPlayerController();
	if (!ensure(Playercontroller != nullptr))
	{
		return;
	}
	Playercontroller->ConsoleCommand("quit");
}

void UMainMenu::OpenJoinMenu()
{
	if (!ensure(MenuSwitcher != nullptr))
	{
		return ;
	}
	if (!ensure(JoinMenu != nullptr))
	{
		return ;
	}
	MenuSwitcher->SetActiveWidget(JoinMenu);
}

void UMainMenu::JoinServer()
{
	if (MenuInterface != nullptr)
	{
		if (!ensure(IPAddressField != nullptr))
		{
			return;
		}
		const FString  & Address = IPAddressField->GetText().ToString();
		MenuInterface->Join(Address);
	}
}
