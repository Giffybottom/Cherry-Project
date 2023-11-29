// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/BaseItem.h"
#include "ConsumableItem.generated.h"

UENUM(BlueprintType)
enum EffectType
{
	EFF_HP UMETA(DisplayName = "Heal"),
	EFF_RESOURCE UMETA(DisplayName = "Resource"),
	EFF_UNKNOWN UMETA(DisplayName = "Unknown")
};
/**
 * 
 */
UCLASS()
class CHERRYPROJECT_API AConsumableItem : public ABaseItem
{
	GENERATED_BODY()

public:
	AConsumableItem();


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Info")
	TEnumAsByte<EffectType> effectType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Info")
		int effectStrength; //itemStrength

	virtual void Use(AInventoryPlayer* player) override;

	
	virtual void OnUse(AInventoryPlayer* player) override;
};
