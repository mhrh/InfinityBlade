// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include"StartUserWidget.h"
#include"RegisterUI.h"
#include "StartGameMode.generated.h"

/**
 * 
 */
UCLASS()
class INFINITYBLADE_API AStartGameMode : public AGameMode
{
	GENERATED_BODY()
public:
	UPROPERTY()
		UStartUserWidget* StartWidget;
	UPROPERTY()
		URegisterUI* RegisterWidget;

public:
	virtual void BeginPlay() override;
	
	UFUNCTION()
		void RegisterBtnCallback();
	
	UFUNCTION()
		void BackBtnCallback();
};
