// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/ConsumableItem.h"
#include "Animation/AnimInstance.h"
#include "WeaponItem.generated.h"

/**
 * 
 */
UCLASS()
class CHERRYPROJECT_API AWeaponItem : public AConsumableItem
{
	GENERATED_BODY()

protected:
	class UAnimInstance* WeaponAnim;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Stat")
	int AttackDamage;

	UAnimInstance* GetWeaponAnimation();
};
