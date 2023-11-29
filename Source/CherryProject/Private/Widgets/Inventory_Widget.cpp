// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/Inventory_Widget.h"

void UInventory_Widget::NativeConstruct()
{
	Super::NativeConstruct();
}

void UInventory_Widget::AddItem(ABaseItem* classRef)
{

	//construct object
	//add item to tile view
	//this is cool stuff
	InventoryTileView->AddItem(classRef);

	//InventoryTileView->

}

void UInventory_Widget::Show()
{
	UE_LOG(LogTemp, Warning, TEXT("FO_SHOW."))
	AddToViewport(9999);
}

void UInventory_Widget::Hide()
{
	RemoveFromViewport();
	UE_LOG(LogTemp, Warning, TEXT("NO_SHOW"))
}
