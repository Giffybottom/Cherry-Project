// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/BaseCharacter.h"
#include "Widgets/BaseHUD.h"
#include "BasePlayer.generated.h"


/**
 * 
 */
UCLASS()
class CHERRYPROJECT_API ABasePlayer : public ABaseCharacter
{
	GENERATED_BODY()

private:


protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Controller")
		class APlayerController* PlayerController;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera");
		class UCameraComponent* Camera;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera");
		class USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		class UBaseHUD* HUD;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variable")
		TSubclassOf<class UBaseHUD> GUI;

	UPROPERTY(visibleAnywhere, BlueprintReadOnly, Category = "Player Stats");
	int PlayerHealth;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Stats");
	int PlayerMaxHealth;


	void MoveUp(float AxisValue);
	void MoveSide(float AxisValue);

	bool isMovementEnabled;


public:
	ABasePlayer();
	virtual void SetupPlayerInputComponent(class UInputComponent* PLayerInputComponent) override;
	virtual void Tick(float deltaTime) override;

	bool SetRefs() override;
	/// <summary>
	/// Increments player health.
	/// A Negative number heals player.
	/// </summary>
	/// <param name="Amount">: amount to increment health in a negative direction</param>
	virtual void IncrementPlayerHealth(int Amount);
};
