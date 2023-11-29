// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/PickUpObject.h"
#include "Actors/InventoryPlayer.h"

// Sets default values
APickUpObject::APickUpObject()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	meshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	meshComp->SetCollisionProfileName("NoCollision");
	Collider = CreateDefaultSubobject<USphereComponent>(TEXT("SphereCollider"));

	meshComp->AttachTo(GetRootComponent());
	Collider->AttachTo(meshComp);

	Collider->OnComponentBeginOverlap.AddDynamic(this, &APickUpObject::OnCollision);

}

// Called when the game starts or when spawned
void APickUpObject::BeginPlay()
{
	Super::BeginPlay();
	
}

void APickUpObject::OnCollision(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//	//if other actor is inventory player. copy to inventory
	AInventoryPlayer* player = Cast<AInventoryPlayer>(OtherActor);
	if (player != nullptr) 
	{
		UE_LOG(LogTemp, Warning, TEXT(" playerNotNull"));
		if (player->AddItem(ID)) //
		{
			UE_LOG(LogTemp, Warning, TEXT(" ItemAdded"));
			Destroy();
		}
	}
}


