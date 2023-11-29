// Fill out your copyright notice in the Description page of Project Settings.

#include "Actors/InventoryPlayer.h"
#include "Widgets/Inventory_Widget.h"
#include "Actors/InventoryComponent.h"
#include "utility/ItemFactory.h"

AInventoryPlayer::AInventoryPlayer()
{

    InventoryComponent = CreateDefaultSubobject<UInventoryComponent>(TEXT("InventoryComponent"));

    isShowingHUD = false;

}

void AInventoryPlayer::BeginPlay()
{
    Super::BeginPlay();

    PlayerController = Cast<APlayerController>(GetController());

    if (this->GetController() == nullptr)
        UE_LOG(LogTemp, Error, TEXT("MAIN CONTROLLER NULL."));

    if (PlayerController == nullptr)
        UE_LOG(LogTemp, Error, TEXT("CONTROLLER NULL."));

    PlayerInventoryHUD = CreateWidget<UInventory_Widget>(PlayerController, HUD_InventoryBase);

    if (PlayerInventoryHUD != nullptr)
    {
        PlayerInventoryHUD->AddToViewport(2);
        PlayerInventoryHUD->Hide();
    }
    else
        UE_LOG(LogTemp, Error, TEXT("HUD NULL."));

    //Creates factory
    ItemFactory = subItemFactory.GetDefaultObject();
    //creates  list for factory
    ItemFactory->ListCreation();
    //used to add a specific item to the inventory component
    ABaseItem* temp = ItemFactory->CopyItem(ItemFactory->GetItem("CN002"));
    UpdateCondition condition = InventoryComponent->PickUpItem(temp);

    if (condition == UpdateCondition::UC_Add)
    {
        PlayerInventoryHUD->AddItem(temp);
    }
}


void AInventoryPlayer::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
    //Super will change to ABasePlayer
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    //Jesse will have to do virtual void override
    InputComponent->BindAction("ToggleInventory", EInputEvent::IE_Pressed, this, &AInventoryPlayer::ToggleInventory);

}

bool AInventoryPlayer::AddItem(FString itemID)
{
    UE_LOG(LogTemp, Warning, TEXT(" IN_Add_Item"));
    ABaseItem* holder = ItemFactory->CopyItem(ItemFactory->GetItem(itemID));
    UpdateCondition condition = InventoryComponent->PickUpItem(holder);

    if (condition == UpdateCondition::UC_Failed)
    {
        return false;
    }
    else if (condition == UpdateCondition::UC_Add)
    {
        PlayerInventoryHUD->AddItem(holder);
        return true;
    }
    else if (condition == UpdateCondition::UC_Increase)
    {

        return true;
    }
     


    return false;
}

void AInventoryPlayer::ToggleInventory()
{
    if (this->GetController() == nullptr)
    {
        UE_LOG(LogTemp, Error, TEXT("TAB CONTROLLER NULL."));
    }
    
    /*APlayerController* InvController = Cast<APlayerController>(GetController());*/

    UE_LOG(LogTemp, Warning, TEXT("Tab was pressed."))

    if (PlayerInventoryHUD == nullptr)
    {
        UE_LOG(LogTemp, Warning, TEXT("PlayerInvHUD is null."))
        return;
    }

    if (!isShowingHUD)
    {
        UE_LOG(LogTemp, Warning, TEXT("Hud is showing."))
            //PlayerInventoryHUD->Show();
            PlayerInventoryHUD->Show();
        isMovementEnabled = false;
        isShowingHUD = true;
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("Hud is not showing."))
        PlayerInventoryHUD->Hide();
        isMovementEnabled = true;
        isShowingHUD = false;
    }
}

