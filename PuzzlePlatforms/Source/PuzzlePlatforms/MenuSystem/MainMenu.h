// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MenuWidget.h"

#include "MainMenu.generated.h"
 
/**
 * 
 */
UCLASS()
class PUZZLEPLATFORMS_API UMainMenu : public UMenuWidget
{
	GENERATED_BODY()
public:
	 void Construct();
	 UMainMenu(const FObjectInitializer & ObjectInitializer);

	 void SetServerList(TArray<FString> ServerNames);

	 void  SelectIndex(uint32 Index);
protected:
		virtual bool Initialize() override;
		virtual void NativeConstruct() override;
		

private:
	TSubclassOf<class UUserWidget> ServerRowClass;
	UPROPERTY(meta = (BindWidget))
		class UButton *QuitButton;
		UPROPERTY(meta = (BindWidget))
		class UButton * HostButton;
	UPROPERTY(meta = (BindWidget))
		class UButton * JoinButton;
	UPROPERTY(meta = (BindWidget))
		class UButton * ConfirmJoinButton;
	UPROPERTY(meta = (BindWidget))
		class UWidgetSwitcher * MenuSwitcher;

	UPROPERTY(meta = (BindWidget))
		class UWidget * JoinMenu;

	UPROPERTY(meta = (BindWidget))
		class UWidget * MainMenu;

	UPROPERTY(meta = (BindWidget))
		class UEditableTextBox * IPAddressField;

	UPROPERTY(meta = (BindWidget))
		class UPanelWidget * ServerList;

	UPROPERTY(meta = (BindWidget))
		class UButton *CancelJoinButton;
	UFUNCTION()
	   void HostServer();
	UFUNCTION()
		void OpenMainMenu();
	UFUNCTION()
		void OpenJoinMenu();
	UFUNCTION() 
		void JoinServer();
	UFUNCTION() 
		void QuitPressed();

	TOptional<uint32> SelectedIndex;
	

};
