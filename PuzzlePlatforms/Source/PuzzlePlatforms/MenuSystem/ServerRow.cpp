// Fill out your copyright notice in the Description page of Project Settings.

#include "ServerRow.h"
#include "Button.h"
#include "MainMenu.h"

void UServerRow::Setup(class UMainMenu * InParent, uint32 InIndex)
{
	this->Parent = InParent;
	this->Index = InIndex;
	RowButton->OnClicked.AddDynamic(this, &UServerRow::OnClicked);
}

void UServerRow::OnClicked()
{
	Parent->SelectIndex(Index);

}
