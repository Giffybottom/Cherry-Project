// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/BasePlayer.h"
#include "InventoryPlayer.generated.h"

/**
 * 
 */
UCLASS()
class CHERRYPROJECT_API AInventoryPlayer : public ABasePlayer
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

	//Widget Related Properties
	UPROPERTY(VisibleAnywhere)
		UUserWidget* UserWidget;
	class UInventory_Widget* PlayerInventoryHUD;

	APlayerController* PlayerController;

	//How to get item factory from the 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variable|Factory")
		TSubclassOf<class UItemFactory> subItemFactory;

public:

	AInventoryPlayer();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		class UInventoryComponent* InventoryComponent;

	//when information is needed inside of a blueprint like a mesh or image
		//think of TSubClassOf, assign this to the parent class of the desired blueprint
			//and then in the owning blueprint class of THIS script set the Tsub to
				//the desired class that is inherited by the blueprint you wish to use.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variable|Class")
		TSubclassOf<class UInventory_Widget> HUD_InventoryBase;	

	//Used for inventory related input (Example: "Tab" = toggle hud, L-Click = Use, etc...)
	void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	//Input Functions and Variables
	void ToggleInventory();
	//
	bool AddItem(FString itemID);
	//Function: upon collision with a base item try to store item in map
	//void AddItem(ABaseItem* item);



private:
	bool isShowingHUD;

	class UItemFactory* ItemFactory;

};
