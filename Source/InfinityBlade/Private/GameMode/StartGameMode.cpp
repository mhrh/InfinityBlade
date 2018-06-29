// Fill out your copyright notice in the Description page of Project Settings.

#include "StartGameMode.h"


void AStartGameMode::BeginPlay()
{
	//GEngine->AddOnScreenDebugMessage(-1,2.f,FColor::Red,TEXT("Hello"));
	StartWidget = CreateWidget<UStartUserWidget>(GetGameInstance(), LoadClass<UStartUserWidget>(this, TEXT("WidgetBlueprint'/Game/UI/BP_StartUI.BP_StartUI'")));
	StartWidget->AddToViewport();
}

