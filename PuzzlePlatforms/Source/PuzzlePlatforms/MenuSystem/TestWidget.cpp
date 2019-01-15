// Fill out your copyright notice in the Description page of Project Settings.

#include "TestWidget.h"
#include "Image.h"
#include "Engine/Texture.h"
#include "Engine/Texture2D.h"
#include "WidgetBlueprintLibrary.h"

void UTestWidget::NativeConstruct()
{
	Super::NativeConstruct();
	UTexture2D * sourceTexture = Cast<UTexture2D>(SourceTexture);
	//这么写编译过不去
	//FSlateBrush makeBrushFromTexture = UWidgetBlueprintLibrary::MakeBrushFromTexture(sourceTexture, sourceTexture->GetSizeX(), sourceTexture->GetSizeY());
	//DisplayImage->SetBrush(makeBrushFromTexture);

	DisplayImage->SetBrushFromTexture(sourceTexture);
	UE_LOG(LogTemp, Log, TEXT("Ready Exe"));
}
