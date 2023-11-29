// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/ProgressBar.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "Components/WidgetSwitcher.h"
#include "BaseHUD.generated.h"

/**
 * 
 */
UCLASS()
class CHERRYPROJECT_API UBaseHUD : public UUserWidget
{
	GENERATED_BODY()
protected:
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
		class UProgressBar* HealthBar;

public:

	UFUNCTION(BlueprintCallable)
		virtual void SetHealth(float percent);
};
