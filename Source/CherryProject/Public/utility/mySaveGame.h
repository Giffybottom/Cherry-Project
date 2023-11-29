// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
//inventory 
#include <map>
#include <unordered_map>
#include "Actors/BaseItem.h"
#include "mySaveGame.generated.h"

/**
 * 
 */


UCLASS()
class CHERRYPROJECT_API UmySaveGame : public USaveGame
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerName")
		FText playerName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerInfo")
		FTransform PlayerLocation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Progress")
		int32 mapIndex;

    UPROPERTY(VisibleAnywhere, Category = Basic)
        FString saveSlotName;

	UPROPERTY(VisibleAnywhere, Category = Basic)
		uint32 userIndex;

	std::multimap<std::string, ABaseItem*> itemsMultimap;
	std::unordered_map<std::string, int> itemCountMap;

    UmySaveGame();
};
