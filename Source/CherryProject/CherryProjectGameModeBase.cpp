// Copyright Epic Games, Inc. All Rights Reserved.

#include "CherryProjectGameModeBase.h"
#include "GameFramework/PlayerController.h"


void ACherryProjectGameModeBase::BeginPlay()
{
	// Get the player controller.
	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();

	// Set the mouse cursor to visible.
	PlayerController->bShowMouseCursor = true;

	PlayerController->SetMouseLocation(100, 100);
}
