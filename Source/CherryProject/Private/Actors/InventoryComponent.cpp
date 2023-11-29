// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/InventoryComponent.h"
#include "Components/Image.h"
#include "Components/TileView.h"
#include "utility/ItemFactory.h"

// Sets default values for this component's properties
UInventoryComponent::UInventoryComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	CurrPlayerInvItemOrder.Reserve(DefaultSizeOfPlayerInv);

	// ...
}

void UInventoryComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...

}

UpdateCondition UInventoryComponent::PickUpItem(ABaseItem* addedItem)
{
	//Create new item object with addedItems information
	ABaseItem* newItem = addedItem;
	
	if (CurrPlayerInvItemOrder.Num() == 0)
	{
		CurrPlayerInvItemOrder.Add(newItem);
		return UC_Add;
	}

	//Are there slots available to add to?
	if (CurrPlayerInvItemOrder.Num() >= maxItems)
	{
		slotsAvailable = false;
	}

	//Check if item is stackable and stack is full
	if (newItem->IsStackable())
	{

		//Loops through current items in inventory
		//Example 1:
		//Item Slot 1 {ID of 1} x 5
		//Item Slot 2 {ID of 2} x 1
		//Item SLot 3 {ID of 1} x 1 (Increased to 2)
		for (size_t i = 0; i < CurrPlayerInvItemOrder.Num(); i++) //may not be what you need.
		{
			//check for item id 
			if (CurrPlayerInvItemOrder[i]->GetItemID() == newItem->GetItemID())
			{
				//can it fit on the stack
				if (CurrPlayerInvItemOrder[i]->ItemAmount > 0 && CurrPlayerInvItemOrder[i]->ItemAmount < maxStack)
				{
					//increase item amount
					CurrPlayerInvItemOrder[i]->ItemAmount++;
					return UC_Increase;
				}
			}
		}
	}

	//Example 2:
	//Item Slot 1 {ID of 1} x 5
	//Item Slot 2 {ID of 2} x 1
	//New Slot Added
	if (slotsAvailable)
	{
		//CurrPlayerInvItemOrder.push_back(addedItem);
		newItem->ItemAmount++;
		CurrPlayerInvItemOrder.Add(newItem);
		return UC_Add;
	}

	return UC_Failed;
}

bool UInventoryComponent::RemoveItem(ABaseItem* removedItem, int cellNum)
{
	//removing the item will not reduce the amount to zero
	if (CurrPlayerInvItemOrder[cellNum]->ItemAmount - 1 != 0)
	{
		CurrPlayerInvItemOrder[cellNum]->ItemAmount--;
		return true;
	}
	else
	{
		//if add item is 'new' then a delete may be needed here
		CurrPlayerInvItemOrder.RemoveAt(cellNum);
	}

	return false;
}


//Functions used for loading and saving
//void UInventoryComponent::SetInventory(std::multimap<std::string, ABaseItem*> savedMap)
//{
//	itemsMultimap = savedMap;
//}
//
//std::multimap<std::string, ABaseItem*> UInventoryComponent::GetInventory()
//{
//	return itemsMultimap;
//}
//
//void UInventoryComponent::SetItemCount(std::unordered_map<std::string, int> savedItemCount)
//{
//	itemCountMap = savedItemCount;
//}
//
//std::unordered_map<std::string, int> UInventoryComponent::GetItemCount()
//{
//	return itemCountMap;
//}
//
//// Called when the game starts


