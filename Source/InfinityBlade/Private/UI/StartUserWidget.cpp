// Fill out your copyright notice in the Description page of Project Settings.

#include "StartUserWidget.h"
#include "Runtime/Engine/Classes/Kismet/KismetSystemLibrary.h"
bool UStartUserWidget::Initialize()
{
	if (!Super::Initialize())
	{
		return false;
	}
	//≥ı ºªØ
	StartBtn = Cast<UButton>(GetWidgetFromName("BtnStart"));
	RegisterBtn = Cast<UButton>(GetWidgetFromName("BtnRegister"));
	QuitBtn = Cast<UButton>(GetWidgetFromName("BtnQuit"));
	QuitBtn->OnClicked.AddDynamic(this, &UStartUserWidget::Quit);
	return true;
}

void UStartUserWidget::Quit()
{
	UKismetSystemLibrary::QuitGame(GetWorld(), nullptr, EQuitPreference::Quit);
}
