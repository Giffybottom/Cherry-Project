// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/BaseCharacter.h"
#include "BaseAI.generated.h"

/**
 * 
 */
UCLASS()
class CHERRYPROJECT_API ABaseAI : public ABaseCharacter
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;

	ABaseAI();
	virtual void Tick(float DeltaTime) override;

	//void BindWaE() override;

	UFUNCTION(BlueprintCallable)
		void WhenPlayerDied();

	//Implement Attack and reload(maybe) when weapons exist and are implemented fully

	UFUNCTION(BlueprintNativeEvent)
		void AIEndTask();

	UFUNCTION(BlueprintNativeEvent)
		void UpdateBlackboard(float Current, float Max);

};
