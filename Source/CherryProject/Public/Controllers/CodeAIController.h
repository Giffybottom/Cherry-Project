// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Perception/AISenseConfig_Sight.h"
#include "Perception/AIPerceptionComponent.h"
#include "CodeAIController.generated.h"

/**
 * 
 */
UCLASS()
class CHERRYPROJECT_API ACodeAIController : public AAIController
{
	GENERATED_BODY()
	
protected:

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		class UPathFollowingComponent* PathComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AI")
		class UAIPerceptionComponent* PerceptionComp;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AI")
		UAISenseConfig_Sight* sightConfig;



public:
	/*ACodeAIController();
	virtual void BeginPlay() override;
	virtual void OnPossess(APawn* InPawn) override;*/

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "AI")
		class UBehaviorTree* BehaviorTree;

};
