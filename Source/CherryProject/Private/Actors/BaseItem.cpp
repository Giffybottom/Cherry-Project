// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/BaseItem.h"

// Sets default values
ABaseItem::ABaseItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	
	//create static mesh component
	ActionText = FText::FromString("ERROR");
	ItemAmount = 0;
	type = ItemType::IT_EMPTY;
	isStackable = false;
	//create sphere Collider component.
}



// Called when the game starts or when spawned
void ABaseItem::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABaseItem::Use(AInventoryPlayer* player)
{
}

void ABaseItem::OnUse(AInventoryPlayer* player)
{
}

void ABaseItem::CopyItem(ABaseItem* copyTo)
{
	copyTo->ActionText = ActionText;
	copyTo->ItemName = ItemName;
	copyTo->Description = Description;
	copyTo->type = type;
	copyTo->ItemID = ItemID;
	copyTo->Sprite = Sprite;
	copyTo->ItemAmount = ItemAmount;
}


void ABaseItem::ClearItem()
{
	ActionText = FText::FromString("ERROR");
	ItemAmount = 0;
	type = ItemType::IT_EMPTY;
	isStackable = false;
}

FString ABaseItem::GetItemID()
{
	return ItemID;
}

FText ABaseItem::GetActionText()
{
	return ActionText;
}

FText ABaseItem::GetNameText()
{
	return ItemName;
}

FText ABaseItem::GetDescText()
{
	return Description;
}

bool ABaseItem::IsStackable()
{
	return isStackable;
}




