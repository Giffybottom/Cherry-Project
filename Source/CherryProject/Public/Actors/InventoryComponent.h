// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include <vector>
#include <map>
#include <unordered_map>
#include <String>
#include "InventoryComponent.generated.h"

UENUM(BlueprintType)
enum UpdateCondition
{
	UC_Increase UMETA(DisplayName = "Increase"),
	UC_Decrease UMETA(DisplayName = "Decrease"),
	UC_Add UMETA(DisplayName = "Add"),
	UC_Remove UMETA(DisplayName = "Remove"),
	UC_Failed UMETA(DisplayName = "Failed")
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CHERRYPROJECT_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UInventoryComponent();

	//Player Inventory Size Variables
	int MaxSizeOfPlayerInv = 3;
	int DefaultSizeOfPlayerInv = 3;
	int CurrSizeOfPlayerInv = DefaultSizeOfPlayerInv;

	//Inventory Containers std::vector does not work well with unreal, convert to TArray	
	//ABaseItem will become newly created Abstract Object Class
	class TArray<class ABaseItem*> CurrPlayerInvItemOrder;
	// [Item 1 * 3] [Item 2 * 1] [Item 1 * 2]

	//Adds item to player inventory
	UpdateCondition PickUpItem(ABaseItem* addedItem);
	//Remove item from player inventory
	bool RemoveItem(ABaseItem* removedItem, int cellNum);

	//Getter and Setter for multi-map and unordered map
	/*void SetInventory(std::multimap<std::string, ABaseItem*> savedMap);

	std::multimap<std::string, ABaseItem*> GetInventory();

	void SetItemCount(std::unordered_map<std::string, int> savedItemCount);

	std::unordered_map<std::string, int>GetItemCount();*/
	
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:
	static const int maxStack = 5;
	static const int maxItems = 3;
	bool slotsAvailable = true;

	//Key/string = ItemID
	//std::multimap<std::string, ABaseItem*> itemsMultimap;
	//std::unordered_map<std::string, int> itemCountMap;
		
};
