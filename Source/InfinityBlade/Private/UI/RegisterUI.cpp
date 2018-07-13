// Fill out your copyright notice in the Description page of Project Settings.

#include "RegisterUI.h"

bool URegisterUI::Initialize()
{
	if (!Super::Initialize())
	{
		return false;
	}
	BackBtn = Cast<UButton>(GetWidgetFromName("BtnBack"));
	RegisterBtn = Cast<UButton>(GetWidgetFromName("BtnRegister"));

	NickNameTextBox = Cast<UEditableTextBox>(GetWidgetFromName(("EditableTextBox_NickName")));
	PasswordTextBox = Cast<UEditableTextBox>(GetWidgetFromName(("EditableTextBox_Password")));
	RePasswordTextBox = Cast<UEditableTextBox>(GetWidgetFromName(("EditableTextBox_RePassword")));

	RegisterBtn->OnClicked.AddDynamic(this, &URegisterUI::RegisterBtnCallback);
	
	CircularThrobber = Cast<UCircularThrobber>(GetWidgetFromName("CircularThrobber_Load"));
	MessageUserWidget = Cast<UMessageUserWidget>(GetWidgetFromName("BP_MessageUI"));
	return true;
}



void URegisterUI::RegisterBtnCallback()
{
	FString nickName = NickNameTextBox->GetText().ToString();
	FString password = PasswordTextBox->GetText().ToString();
	FString rePassword = RePasswordTextBox->GetText().ToString();
	if (nickName.Len()<2||nickName.Len()>6)
	{
		MessageUserWidget->SetVisibility(ESlateVisibility::Visible);
		MessageUserWidget->MsgBlock->SetText(FText::FromString("NiceName2-6"));
		return;
	}
	if (!password.Equals(rePassword))
	{
		MessageUserWidget->SetVisibility(ESlateVisibility::Visible);
		MessageUserWidget->MsgBlock->SetText(FText::FromString("password not right"));
		return;
	}
	CircularThrobber->SetVisibility(ESlateVisibility::Visible);
	RegisterBtn->SetIsEnabled(false);
	AccountRegister(nickName, password);
}

void URegisterUI::AccountRegister(FString & nickname, FString & password)
{
	FString RegisterInfo;
	TSharedRef<TJsonWriter<TCHAR, TCondensedJsonPrintPolicy<TCHAR>>> JsonWrite = TJsonWriterFactory<TCHAR, TCondensedJsonPrintPolicy<TCHAR>>::Create(&RegisterInfo);
	JsonWrite->WriteObjectStart();
	JsonWrite->WriteValue("nickname", nickname);
	JsonWrite->WriteValue("password", password);
	JsonWrite->WriteObjectEnd();
	/** 关闭Json写入器 */
	JsonWrite->Close();

	TSharedRef<IHttpRequest> HttpRequest = FHttpModule::Get().CreateRequest();

	/** 设置请求方式 */
	HttpRequest->SetVerb("POST");
	/** 设置请求头 */
	HttpRequest->SetHeader("Content-Type", "application/json;charset=utf-8");
	HttpRequest->SetURL("http://127.0.0.1:7900/user/register-user");
	HttpRequest->SetContentAsString(RegisterInfo);
	HttpRequest->OnProcessRequestComplete().BindUObject(this, &URegisterUI::RequestComplete);
	HttpRequest->ProcessRequest();

	


}

void URegisterUI::RequestComplete(FHttpRequestPtr requestptr, FHttpResponsePtr responsePtr, bool issuccess)
{
	CircularThrobber->SetVisibility(ESlateVisibility::Hidden);
	RegisterBtn->SetIsEnabled(true);
	//int32 code  = responsePtr->GetResponseCode();
	//UE_LOG(LogTemp, Warning, TEXT("MyCharacter's Health is %d"), code);
	if (!EHttpResponseCodes::IsOk(responsePtr->GetResponseCode()))
	{
		return;
	}

	//
	FString data = responsePtr->GetContentAsString();
	
	TSharedPtr<FJsonObject> jsonobj;
	TSharedRef<TJsonReader<TCHAR>> JsonReader = TJsonReaderFactory<TCHAR>::Create(data);
	bool bisPase = FJsonSerializer::Deserialize(JsonReader, jsonobj);
	if (bisPase)
	{
		FString status =	jsonobj->GetStringField("status");
		FString msg = jsonobj->GetStringField("msg");
		//FString status = jsonobj->GetStringField("status");
		MessageUserWidget->SetVisibility(ESlateVisibility::Visible);
		MessageUserWidget->MsgBlock->SetText(FText::FromString(msg));
		//GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, status);
	}
}





