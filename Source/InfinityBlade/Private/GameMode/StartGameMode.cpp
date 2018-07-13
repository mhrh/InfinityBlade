// Fill out your copyright notice in the Description page of Project Settings.

#include "StartGameMode.h"


void AStartGameMode::BeginPlay()
{
	//GEngine->AddOnScreenDebugMessage(-1,2.f,FColor::Red,TEXT("Hello"));
	//StartWidget = CreateWidget<UStartUserWidget>(GetGameInstance(), LoadClass<UStartUserWidget>(this, TEXT("WidgetBlueprint'/Game/UI/BP_StartUI.BP_StartUI'_C")));
	//StartWidget->AddToViewport();
	StartWidget = CreateWidget<UStartUserWidget>(GetGameInstance(), LoadClass<UStartUserWidget>(this, TEXT("WidgetBlueprint'/Game/UI/BP_StartUI.BP_StartUI_C'")));
	StartWidget->AddToViewport();

	StartWidget->RegisterBtn->OnClicked.AddDynamic(this, &AStartGameMode::RegisterBtnCallback);
	
	RegisterWidget = CreateWidget<URegisterUI>(GetGameInstance(), LoadClass<URegisterUI>(this, TEXT("WidgetBlueprint'/Game/UI/BP_RegisterUI.BP_RegisterUI_C'")));
	RegisterWidget->BackBtn->OnClicked.AddDynamic(this,&AStartGameMode::BackBtnCallback);
}

void AStartGameMode::RegisterBtnCallback()
{
	StartWidget->RemoveFromViewport();
	RegisterWidget->AddToViewport();
}

void AStartGameMode::BackBtnCallback()
{
	RegisterWidget->RemoveFromViewport();
	StartWidget->AddToViewport();
}