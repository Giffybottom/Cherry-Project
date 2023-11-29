// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/BaseAI.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "GameFramework/Pawn.h"

ABaseAI::ABaseAI()
{
	PrimaryActorTick.bCanEverTick = false;
	PrimaryActorTick.bStartWithTickEnabled = false;
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;
	//AIController = Cast<ABaseAIController>(GetController());
}

void ABaseAI::BeginPlay()
{
	Super::BeginPlay();
	//AnimBP->OnShotEnded.AddDynamic(this, &ABaseAI::AIEndTask);
	//Weapon->OnAmmoUpdate.AddDynamic(this, &ABaseAI::UpdateBlackboard);
	//Weapon->Reload();
}

void ABaseAI::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//Attack();
}

void ABaseAI::WhenPlayerDied()
{
	SetActorTickEnabled(false);
}

void ABaseAI::AIEndTask_Implementation()
{
	//UAIBlueprintHelperLibrary::SendAIMessage(this, FName(TEXT("ActionEnded")), AnimBP);
}

void ABaseAI::UpdateBlackboard_Implementation(float Current, float Max)
{
	/*ABaseAIController* Control = Cast<ABaseAIController>(GetController());
	Control->GetBlackboardComponent()->SetValueAsFloat(FName(TEXT("Ammo")), Current);*/

	//AController* Control = GetController();
	//AAIController* AIControl = nullptr;
	//if (Control)
	//	AIControl = Cast<AAIController>(Control);
	//else
		//UE_LOG(Game, Error, TEXT("BaseAI.cpp GetController fail"));

	//if (AIControl)
	//{
	//	AIControl->GetBlackboardComponent()->SetValueAsFloat(FName(TEXT("Ammo")), Current);
	//}
	//else
		//UE_LOG(Game, Error, TEXT("BaseAI.cpp cast to AAIController fail"));
}