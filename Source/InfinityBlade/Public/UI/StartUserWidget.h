// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "StartUserWidget.generated.h"

/**
 * 游戏开始界面
 */
UCLASS()
class INFINITYBLADE_API UStartUserWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	//开始按钮
	UPROPERTY()
		UButton* StartBtn;
	//注册按钮
	UPROPERTY()
		UButton* RegisterBtn;
	//退出按钮
	UPROPERTY()
		UButton* QuitBtn;
	
public:
	/*初始化*/
	virtual bool Initialize() override;
	UFUNCTION()
		void Quit();
};
