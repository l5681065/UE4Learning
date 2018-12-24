// Fill out your copyright notice in the Description page of Project Settings.

#include "MenuWidget.h"


void UMenuWidget::Setup()
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

void UMenuWidget::Teardown()
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
void UMenuWidget::SetMenuInterface(IMenuInterface *MenuInterface)
{
	this->MenuInterface = MenuInterface;
}
