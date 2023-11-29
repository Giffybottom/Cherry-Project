// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "InvEntry.generated.h"


/**
 * 
 */
UCLASS()
class CHERRYPROJECT_API UInvEntry : public UUserWidget
{
	GENERATED_BODY()

protected:
	//UTexture2D
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		class UTexture2D* imageTexture;
	//UImage
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		class UImage* imageEntry;
	//FText ActionText
	UPROPERTY(BlueprintReadWrite)
		FText entryActionText;
	//FText ItemName
	UPROPERTY(BlueprintReadWrite)
		FText entryItemName;
	//FText Description
	UPROPERTY(BlueprintReadWrite)
		FText entryItemDescription;
	//int item amount
	UPROPERTY(BlueprintReadWrite)
		int entryItemAmount;
	
};
