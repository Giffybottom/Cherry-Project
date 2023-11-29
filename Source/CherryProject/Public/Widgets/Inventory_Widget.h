// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Image.h"
#include "Components/TileView.h"
#include "Actors/BaseItem.h"
#include "Inventory_Widget.generated.h"

/**
 * 
 */

class UTileView;
class UInvEntry;

UCLASS()
class CHERRYPROJECT_API UInventory_Widget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	virtual void NativeConstruct() override;


	//Tile View is used to give a grid structure to the inventory. 
	//It equally spaces each "entry" of a specific class reference.
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
		UTileView* InventoryTileView;
	UPROPERTY(EditAnywhere)
		TSubclassOf<UInvEntry> InventorySlotClass;

	UFUNCTION()
	void AddItem(ABaseItem* classRef);
	void Show();
	void Hide();

};
