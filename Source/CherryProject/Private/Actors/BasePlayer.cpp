// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/BasePlayer.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Widgets/BaseHUD.h"
#include "Actors/HealthComponent.h"
//#include "GameFramework/GameFramework.h"

ABasePlayer::ABasePlayer()
{
	SpringArm = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	Camera = CreateDefaultSubobject<UCameraComponent>("Camera");
	SpringArm->SetRelativeLocation(FVector(0, 80, 90));
	SpringArm->TargetArmLength = 210;

	SpringArm->SetupAttachment(RootComponent);
	SpringArm->bUsePawnControlRotation = true;

	Camera->SetupAttachment(SpringArm);

	isMovementEnabled = true;
}

void ABasePlayer::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("GoUp", this, &ABasePlayer::MoveUp);
	PlayerInputComponent->BindAxis("GoLeft", this, &ABasePlayer::MoveSide);
}

void ABasePlayer::Tick(float deltaTime)
{
	Super::Tick(deltaTime);
	
	FVector MouseLocation;
	FVector MouseDirection;

	APlayerController* PController = GetWorld()->GetFirstPlayerController();

	PController->bShowMouseCursor = true;

	float xMouse;
	float yMouse;

	PController->GetMousePosition(xMouse, yMouse);

	FVector CharacterLoc = GetActorLocation();

	FVector2D CharInScreen;
	PController->ProjectWorldLocationToScreen(CharacterLoc, CharInScreen);

	/*FVector2D ScreenToWorld = PController->ConvertScreenLocationToWorldSpace(CharInScreen);*/
	FVector2D Result;
	Result.X = -(yMouse - CharInScreen.Y);
	Result.Y = xMouse - CharInScreen.X;

	// Get angle rotation and rotation Character
	float angle = FMath::RadiansToDegrees(FMath::Acos(Result.X / Result.Size()));

	if (Result.Y < 0)
	{
		angle = 360 - angle;
	}

	FRotator rotation(0, angle, 0);


	//SetActorRotation(rotation);
	if(isMovementEnabled)
	GetMesh()->SetRelativeRotation(rotation);
}

void ABasePlayer::IncrementPlayerHealth(int Amount)
{

	PlayerHealth -= Amount;

	if (PlayerHealth <= 0)
	{
		//player dies
		PlayerHealth = 0;
	}
	else if (PlayerHealth >= PlayerMaxHealth)
	{
		//prevents over Healing
		PlayerHealth = PlayerMaxHealth;
	}

	//update any Player Health UI

}
void ABasePlayer::BeginPlay()
{
	Super::BeginPlay();
	PlayerController = Cast<APlayerController>(GetController());
	/*if (HUD == nullptr)
	{
		HUD = CreateWidget<UBaseHUD>(GetWorld(), GUI);
	}
	HUD->AddToViewport();
	HealthComponent->OnDamage.AddDynamic(HUD, &UBaseHUD::SetHealth);
	HealthComponent->OnDeath.AddDynamic(HUD, &UBaseHUD::SetHealth);
	HealthComponent->OnHealed.AddDynamic(HUD, &UBaseHUD::SetHealth);*/

}

void ABasePlayer::MoveUp(float AxisValue)
{

	//Used for Debugging KeyPress
	if (AxisValue > 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("W is pressed"));
	}
	else if(AxisValue < 0)
		UE_LOG(LogTemp, Warning, TEXT("S is pressed"));

	//disables movement
	if (!isMovementEnabled)
		return;

	FVector Forward = GetActorForwardVector();
	AddMovementInput(Forward, AxisValue);
}

void ABasePlayer::MoveSide(float AxisValue)
{

	//Used for Debugging KeyPress
	if (AxisValue > 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("D is pressed"));
	}
	else if (AxisValue < 0)
		UE_LOG(LogTemp, Warning, TEXT("A is pressed"));

	//disables movement.
	if (!isMovementEnabled)
		return;

	FVector Right = GetActorRightVector();
	AddMovementInput(Right, AxisValue);
}

bool ABasePlayer::SetRefs() {
	Super::SetRefs();

	if (!HUD)
	{
		HUD = CreateWidget<UBaseHUD>(GetWorld(), GUI);
	}

	if (HUD == nullptr) {
		return false;
	}
	return true;
}