// Fill out your copyright notice in the Description page of Project Settings.

#include "StartUserWidget.h"

bool UStartUserWidget::Initialize()
{
	if (!Super::Initialize())
	{
		return false;
	}
	//≥ı ºªØ
	StartBtn = Cast<UButton>(GetWidgetFromName("StartBtn"));
	RegisterBtn = Cast<UButton>(GetWidgetFromName("RegisterBtn"));
	QuitBtn = Cast<UButton>(GetWidgetFromName("QuitBtn"));
	return true;
}
