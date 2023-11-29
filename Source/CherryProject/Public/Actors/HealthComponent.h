// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FHealthDelegate, float, percent);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CHERRYPROJECT_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHealthComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float MaxHP;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
		float CurHP;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float percent;
	UFUNCTION(BlueprintCallable, Category = "Function")
		virtual bool IsFullHealth() const;

	UPROPERTY(BlueprintAssignable, BlueprintCallable)
		FHealthDelegate OnDamage;
	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Variable")
		FHealthDelegate OnDeath;
	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Variable")
		FHealthDelegate OnHealed;

	void InitHP();

	UFUNCTION()
		void DamageTaken(AActor* DamagedActor, float Damage, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser);

	UFUNCTION(BlueprintPure, BlueprintInternalUseOnly)
		float GetValue() const;
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly)
		void SetValue(const float val);

};
