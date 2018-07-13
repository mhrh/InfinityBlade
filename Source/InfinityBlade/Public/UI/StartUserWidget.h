// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "StartUserWidget.generated.h"

/**
 * ��Ϸ��ʼ����
 */
UCLASS()
class INFINITYBLADE_API UStartUserWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	//��ʼ��ť
	UPROPERTY()
		UButton* StartBtn;
	//ע�ᰴť
	UPROPERTY()
		UButton* RegisterBtn;
	//�˳���ť
	UPROPERTY()
		UButton* QuitBtn;
	
public:
	/*��ʼ��*/
	virtual bool Initialize() override;
	UFUNCTION()
		void Quit();
};
