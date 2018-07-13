// Fill out your copyright notice in the Description page of Project Settings.

#include "MessageUserWidget.h"

bool UMessageUserWidget::Initialize()
{
	if (!Super::Initialize())
	{
		return false;
	}
	CloseBtn = Cast<UButton>(GetWidgetFromName(TEXT("Button_Close")));
	MsgBlock = Cast<UTextBlock>(GetWidgetFromName("TextBlock_Msg"));
	
	CloseBtn->OnClicked.AddDynamic(this,&UMessageUserWidget::CloseBtnCallback);
	return true;
}
void UMessageUserWidget::CloseBtnCallback()
{
	this->SetVisibility(ESlateVisibility::Hidden);
}