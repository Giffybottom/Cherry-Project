// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Engine/DataTable.h"
#include "Actors/WeaponItem.h"
#include "ItemFactory.generated.h"


USTRUCT(BlueprintType) struct FItemConverter : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TEnumAsByte<ItemType> type;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ID;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText Action;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText Desc;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText Name;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UTexture2D* sprite;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool stack;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TEnumAsByte<EffectType> effType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int effStr;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int attStr;
	
	FItemConverter& FItemConverter::operator =(const FItemConverter& other)
	{

		type = other.type;
		ID = other.ID;
		Action = other.Action;
		Desc = other.Desc;
		Name = other.Name;
		sprite = other.sprite;
		stack = other.stack;
		effType = other.effType;
		effStr = other.effStr;
		attStr = other.attStr;

		return *this;
	}
};
/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class CHERRYPROJECT_API UItemFactory : public UObject
{

	GENERATED_BODY()

public:
	UItemFactory();


	//TArray<ABaseItem*> ItemList;
	TMap<FString, ABaseItem*> ItemList;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Sprites")
	TArray<UTexture2D*> ItemSprite;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Database")
	class UDataTable* ItemTable;

		
	UFUNCTION()
	void ListCreation();

	ABaseItem* GetItem(FString ID);

	ABaseItem* CopyItem(ABaseItem* item);
	

private:
	ABaseItem* CreateItem(FText action, FText name, FText desc, TEnumAsByte<ItemType> _type, FString ID, bool stackable, UTexture2D* sprite);

	AConsumableItem* CreateConsumable(FText action, FText name, FText desc, TEnumAsByte<ItemType> _type, FString ID, bool stackable, UTexture2D* sprite, int effecStrength, TEnumAsByte<EffectType> effectType);

	AWeaponItem* CreateWeapon(FText action, FText name, FText desc, TEnumAsByte<ItemType> _type, FString ID, bool stackable, UTexture2D* sprite, int effecStrength, TEnumAsByte<EffectType> effectType, int attackDamage);


};
