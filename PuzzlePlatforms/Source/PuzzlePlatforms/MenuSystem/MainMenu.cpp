// Fill out your copyright notice in the Description page of Project Settings.

#include "MainMenu.h"
#include "Components/Button.h"
#include "Components/WidgetSwitcher.h"
#include "Components/EditableTextBox.h"

void UMainMenu::SetMenuInterface(IMenuInterface *MenuInterface)
{
	this->MenuInterface = MenuInterface;
}

void UMainMenu::Setup()
{
	this->AddToViewport();

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
	FInputModeUIOnly InputModeData;
	InputModeData.SetWidgetToFocus(this->TakeWidget());
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);

	Playercontroller->SetInputMode(InputModeData);
	Playercontroller->bShowMouseCursor = true;
}

void UMainMenu::Teardown()
{
	this->RemoveFromViewport();
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
	FInputModeGameOnly InputModeData;
	Playercontroller->SetInputMode(InputModeData);
	Playercontroller->bShowMouseCursor = false;

}

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
	 return true;
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
