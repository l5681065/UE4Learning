// Fill out your copyright notice in the Description page of Project Settings.

#include "MainMenu.h"
#include "Components/Button.h"
#include "Components/WidgetSwitcher.h"
#include "Components/EditableTextBox.h"
#include "ConstructorHelpers.h"
#include "Components/TextBlock.h"
#include "ServerRow.h"


UMainMenu::UMainMenu(const FObjectInitializer & ObjectInitializer)
{
	ConstructorHelpers::FClassFinder<UUserWidget > ServerRowBPClass(TEXT("/Game/MenuSystem/WBP_ServerRow"));
	if (!ensure(ServerRowBPClass.Class != nullptr))
	{
		return;
	} 
	ServerRowClass = ServerRowBPClass.Class;
}


void UMainMenu::SetServerList(TArray<FString> ServerNames)
{
	UWorld * World = this->GetWorld();
	if (!ensure(World != nullptr))
	{
		return;
	}
	uint32 i = 0;
	ServerList->ClearChildren();
	for (const FString & ServerName:ServerNames)
	{
		UServerRow* Row = CreateWidget<UServerRow>(World, ServerRowClass);
		if (!ensure(Row != nullptr))
		{
			return;
		}
		Row->ServerName->SetText(FText::FromString(ServerName));
		Row->Setup(this,i);
		++i;
		ServerList->AddChild(Row);
	}
	
	
}


void UMainMenu::SelectIndex(uint32 Index)
{
	SelectedIndex = Index;
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
	if (MenuInterface!=nullptr)
	{
		MenuInterface->RefreshServerList();
	}
}

void UMainMenu::JoinServer()
{
	if (SelectedIndex.IsSet())
	{
		UE_LOG(LogTemp, Warning, TEXT("Selected index %d"),SelectedIndex.GetValue());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Selected Index not set"));
	}
	if (MenuInterface != nullptr)
	{
		/*if (!ensure(IPAddressField != nullptr))
		{
			return;
		}
		const FString  & Address = IPAddressField->GetText().ToString();*/
		MenuInterface->Join("");

	}
}
