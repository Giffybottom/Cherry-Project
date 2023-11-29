// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/BaseHUD.h"
#include "Components/ProgressBar.h"
#include "Components/Image.h"

void UBaseHUD::SetHealth(float percent) {
	HealthBar->SetPercent(percent);
}