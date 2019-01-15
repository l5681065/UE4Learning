// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"


#include "TestWidget.generated.h"

class UImage;
class UTexture;

/**
 * 
 */
UCLASS()
class PUZZLEPLATFORMS_API UTestWidget : public UUserWidget
{
	GENERATED_BODY()
protected:
	virtual void NativeConstruct() override;
public:
	UPROPERTY(meta = (BindWidget))
		UImage *  DisplayImage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UTexture * SourceTexture;
	
};
