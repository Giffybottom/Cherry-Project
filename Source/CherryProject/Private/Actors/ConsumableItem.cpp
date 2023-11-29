// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/ConsumableItem.h"


AConsumableItem::AConsumableItem() : ABaseItem()
{
	effectStrength = 1;
	effectType = EffectType::EFF_HP;
	type = ItemType::IT_CONSUMABLE;
	ActionText = FText::FromString("Use");
}


void AConsumableItem::Use(AInventoryPlayer* player)
{
	//grab player health and increment it
	ABaseItem::Use(player);
	player->IncrementPlayerHealth(effectStrength);
}

void AConsumableItem::OnUse(AInventoryPlayer* player)
{
	ABaseItem::OnUse(player);
}
