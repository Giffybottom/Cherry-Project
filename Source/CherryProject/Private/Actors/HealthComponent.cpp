// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/HealthComponent.h"

// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	PrimaryComponentTick.bCanEverTick = false;
	MaxHP = 5.0f;
}


// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();
	InitHP();
	GetOwner()->OnTakeAnyDamage.AddDynamic(this, &UHealthComponent::DamageTaken);

}


// Called every frame
void UHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UHealthComponent::InitHP() {
	CurHP = MaxHP;
}

bool UHealthComponent::IsFullHealth() const {
	if (CurHP / MaxHP > 0.99)
		return true;
	return false;
}

void UHealthComponent::DamageTaken(AActor* DamagedActor, float Damage,
	const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser)
{
	CurHP = FMath::Clamp(CurHP - Damage, 0.0f, MaxHP);
	percent = CurHP / MaxHP;
	if (CurHP > 0.0f) {
		OnDamage.Broadcast(percent);
		if (Damage < 0.0f)
			OnHealed.Broadcast(percent);
	}
	else {
		OnDamage.Clear();
		GetOwner()->OnTakeAnyDamage.Clear();
		OnDeath.Broadcast(percent);
	}
}

float UHealthComponent::GetValue() const {
	return CurHP;
}

void UHealthComponent::SetValue(const float val) {
	CurHP = val;
}