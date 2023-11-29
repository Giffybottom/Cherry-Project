// Fill out your copyright notice in the Description page of Project Settings.


#include "utility/ItemFactory.h"

UItemFactory::UItemFactory()
{
	ListCreation();
}





void UItemFactory::ListCreation()
{

	static ConstructorHelpers::FObjectFinder<UDataTable> objectTable(TEXT("DataTable'/Game/Database/FactoryDataTable.FactoryDataTable'"));
	ItemTable = objectTable.Object;

	if (!ItemTable)
	{
		UE_LOG(LogTemp, Warning, TEXT(" Table was Null!"));
	}
	else { UE_LOG(LogTemp, Error, TEXT(" Table was NOT Null!")); }

	TArray<FName> names = ItemTable->GetRowNames();


	static const FString context(TEXT("Some Weird Stuff Going on here"));
	int count = names.Num();

	UE_LOG(LogTemp, Warning, TEXT(" Name Count: %d"), count);

	for (size_t i = 0; i < names.Num(); i++)
	{
		FItemConverter* holder = ItemTable->FindRow<FItemConverter>(names[i], context, false);

		
		if (holder == nullptr)
		{
			UE_LOG(LogTemp, Warning, TEXT(" Holder was Null!"));
			continue;
		}
		switch (holder->type)
		{
		case ItemType::IT_WEAPON:
			ItemList.Add(holder->ID, CreateWeapon(holder->Action, holder->Name, holder->Desc, holder->type, holder->ID, holder->stack, holder->sprite, holder->effStr, holder->effType, holder->attStr));
			break;
		case ItemType::IT_CONSUMABLE:
			ItemList.Add(holder->ID, CreateConsumable(holder->Action, holder->Name, holder->Desc, holder->type, holder->ID, holder->stack, holder->sprite, holder->effStr, holder->effType));
			break;
		case ItemType::IT_KEY:
			ItemList.Add(holder->ID, CreateItem(holder->Action, holder->Name, holder->Desc, holder->type, holder->ID, holder->stack, holder->sprite));
			break;
		}
	}
	UE_LOG(LogTemp, Warning, TEXT(" Item Bank Count: %d"), ItemList.Num());
}

ABaseItem* UItemFactory::GetItem(FString ID)
{
	UE_LOG(LogTemp, Warning, TEXT(" IN_GET_ITEM"));
	if (ItemList.Contains(ID))
		return ItemList[ID];
	else
		return ItemList["KY001"];
}

ABaseItem* UItemFactory::CreateItem(FText action, FText name, FText desc, TEnumAsByte<ItemType> _type, FString ID, bool stackable, UTexture2D* sprite)
{

	ABaseItem* newItem = NewObject<ABaseItem>();
	newItem->ActionText = action;
	newItem->ItemName = name;
	newItem->Description = desc;
	newItem->type = _type;
	newItem->ItemID = ID;
	newItem->isStackable = stackable;
	newItem->Sprite = sprite;

	return newItem;
}

AConsumableItem* UItemFactory::CreateConsumable(FText action, FText name, FText desc, TEnumAsByte<ItemType> _type, FString ID, bool stackable, UTexture2D* sprite, int effecStrength, TEnumAsByte<EffectType> effectType)
{
	AConsumableItem* newItem = NewObject<AConsumableItem>();

	newItem->ActionText = action;
	newItem->ItemName = name;
	newItem->Description =desc;
	newItem->type = _type;
	newItem->ItemID = ID;
	newItem->isStackable = stackable;
	newItem->effectStrength = effecStrength;
	newItem->effectType = effectType;
	newItem->Sprite = sprite;
	return newItem;
}

AWeaponItem* UItemFactory::CreateWeapon(FText action, FText name, FText desc, TEnumAsByte<ItemType> _type, FString ID, bool stackable, UTexture2D* sprite, int effecStrength, TEnumAsByte<EffectType> effectType, int attackDamage)
{
	AWeaponItem* newItem = NewObject<AWeaponItem>();

	newItem->ActionText = action;
	newItem->ItemName = name;
	newItem->Description = desc;
	newItem->type = _type;
	newItem->ItemID = ID;
	newItem->isStackable = stackable;
	newItem->effectStrength = effecStrength;
	newItem->effectType = effectType;
	newItem->AttackDamage = attackDamage;
	newItem->Sprite = sprite;
	return newItem;
}

ABaseItem* UItemFactory::CopyItem(ABaseItem* item)
{
	AWeaponItem* wep = nullptr; AWeaponItem* wepConvert = nullptr;
	AConsumableItem* con = nullptr; AConsumableItem* conConvert = nullptr;
	ABaseItem* key = nullptr; 	ABaseItem* keyConvert = nullptr;

	UE_LOG(LogTemp, Warning, TEXT(" COPY_TOP"));

	switch (ItemList[item->ItemID]->type)
	{
	case ItemType::IT_CONSUMABLE:
		con = NewObject<AConsumableItem>();
		conConvert = Cast<AConsumableItem>(item);


		con->ActionText = conConvert->ActionText;
		con->ItemName = conConvert->ItemName;
		con->Description = conConvert->Description;
		con->type = conConvert->type;
		con->ItemID = conConvert->ItemID;
		con->isStackable = conConvert->isStackable;
		con->effectStrength = conConvert->effectStrength;
		con->effectType = conConvert->effectType;
		con->Sprite = conConvert->Sprite;

		UE_LOG(LogTemp, Warning, TEXT(" COPY_ONE"));
		return con;
	case ItemType::IT_WEAPON:
		wep = NewObject<AWeaponItem>();
		wepConvert = Cast<AWeaponItem>(item);

		wep->ActionText = wepConvert->ActionText;
		wep->ItemName = wepConvert->ItemName;
		wep->Description = wepConvert->Description;
		wep->type = wepConvert->type;
		wep->ItemID = wepConvert->ItemID;
		wep->isStackable = wepConvert->isStackable;
		wep->effectStrength = wepConvert->effectStrength;
		wep->effectType = wepConvert->effectType;
		wep->AttackDamage = wepConvert->AttackDamage;
		wep->Sprite = wepConvert->Sprite;
		UE_LOG(LogTemp, Warning, TEXT(" COPY_TWO"));
		return wep;
	case ItemType::IT_KEY:
		key = NewObject<ABaseItem>();
		keyConvert = Cast<ABaseItem>(item);

		key->ActionText = keyConvert->ActionText;
		key->ItemName = keyConvert->ItemName;
		key->Description = keyConvert->Description;
		key->type = keyConvert->type;
		key->ItemID = keyConvert->ItemID;
		key->isStackable = keyConvert->isStackable;
		key->Sprite = keyConvert->Sprite;
		UE_LOG(LogTemp, Warning, TEXT(" COPY_THREE"));
		return key;
	default:
		break;
	}

	UE_LOG(LogTemp, Warning, TEXT(" COPY_END"));
	return nullptr;
}
