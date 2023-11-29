// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Actors/InventoryPlayer.h"
#include "Engine/Texture2D.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "BaseItem.generated.h"


UENUM(BlueprintType)
enum ItemType
{
	IT_KEY UMETA(DisplayName = "KeyItem"),
	IT_CONSUMABLE UMETA(DisplayName = "ConsumableItem"),
	IT_WEAPON UMETA(DisplayName = "WeaponItem"),
	IT_EMPTY UMETA(DisplayName = "EMPTY")
};

UCLASS()
class CHERRYPROJECT_API ABaseItem : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ABaseItem();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:
	//Amount used for stack.
	uint8 ItemAmount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI Text")
		FText ActionText;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI Text")
		FText ItemName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI Text")
		FText Description;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Info")
		TEnumAsByte<ItemType> type;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Info")
		FString ItemID;

	bool isStackable;
	//2DTexture
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Sprite");
	class UTexture2D* Sprite;



	virtual void Use(AInventoryPlayer* player);

	UFUNCTION()
	virtual void OnUse(AInventoryPlayer* player);

	/// <summary>
	/// Used In Inventory to copy Item Values.
	/// </summary>
	virtual void CopyItem(ABaseItem* copyTo);

	/// <summary>
	/// Used In Inventory to clear Item Values.
	/// !!!!ONLY CALL IN INVENTORY!!!!
	/// </summary>
	virtual void ClearItem();

	FString GetItemID();

	FText GetActionText();
	FText GetNameText();
	FText GetDescText();
	bool IsStackable();

};
