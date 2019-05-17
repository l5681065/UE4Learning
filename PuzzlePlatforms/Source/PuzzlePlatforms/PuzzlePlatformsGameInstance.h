// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MenuSystem/MenuInterface.h"
#include "OnlineSubsystem.h"
#include "PuzzlePlatformsGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class PUZZLEPLATFORMS_API UPuzzlePlatformsGameInstance : public UGameInstance,public IMenuInterface
{
	GENERATED_BODY()
public:
	UPuzzlePlatformsGameInstance(const FObjectInitializer & ObjectInitializer);

	virtual void Init();
	
	UFUNCTION(BlueprintCallable)
		void LoadMenuWidget();
	UFUNCTION(BlueprintCallable)
		void InGameLoadMenu();
	UFUNCTION(Exec)
		void Host () override;
	UFUNCTION(Exec)
		void Join(const FString & Address) override;
	UFUNCTION()
		void Foobar()override;

	virtual void LoadMainMenu() override;

	virtual void RefreshServerList()	override;

private:
	TSubclassOf<UUserWidget> MenuClass;
	TSubclassOf<UUserWidget> InGameMenuClass;
	class UMainMenu * Menu;
	class UInGameMenu * InGameMenu;

	IOnlineSessionPtr SessionInterface;

	void OnCreateSessionComplete(FName Session,bool Success);
	void OnDestorySessionComplete(FName Session,bool Success);
	void OnFindSessionComplete(bool Success);
	void CreateSession();

	TSharedPtr<class FOnlineSessionSearch> SessionSearch; 
};
