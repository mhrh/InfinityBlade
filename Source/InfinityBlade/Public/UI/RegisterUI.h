// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Components/EditableTextBox.h"
#include "Runtime/Online/HTTP/Public/HttpModule.h"
#include "Runtime/Json/Public/Serialization/JsonWriter.h"
#include "Runtime/Online/HTTP/Public/Interfaces/IHttpRequest.h"
#include "Runtime/Json/Public/Serialization/JsonSerializer.h"
#include "Runtime/Online/HTTP/Public/Interfaces/IHttpResponse.h"
#include "Runtime/UMG/Public/Components/CircularThrobber.h"
#include "UI/MessageUserWidget.h"
#include "RegisterUI.generated.h"
/**
 * 
 */
UCLASS()
class INFINITYBLADE_API URegisterUI : public UUserWidget
{
	GENERATED_BODY()
	
public:
	
	UPROPERTY()
		UButton* BackBtn;
	UPROPERTY()
		UButton* RegisterBtn;
	UPROPERTY()
		UEditableTextBox* NickNameTextBox;
	UPROPERTY()
		UEditableTextBox* PasswordTextBox;
	UPROPERTY()
		UEditableTextBox* RePasswordTextBox;

	UPROPERTY()
		UCircularThrobber*CircularThrobber;

	UPROPERTY()
		UMessageUserWidget*MessageUserWidget;

	virtual bool Initialize() override;


	UFUNCTION()
	void RegisterBtnCallback();

	void AccountRegister(FString& nickname, FString& password);

	void RequestComplete(FHttpRequestPtr requestptr,FHttpResponsePtr responsePtr,bool issuccess);
};
