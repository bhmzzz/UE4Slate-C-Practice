// Fill out your copyright notice in the Description page of Project Settings.


#include "SlAiStyleClass.h"
#include "Slate/SlateGameResources.h"

TSharedPtr<FSlateStyleSet> SlAiStyleClass::SlAiStyleInstance = NULL;//��ʼ��

void SlAiStyleClass::Initialze()
{
	//������������ھ͹���Ȼ��ע�����Ϸ
	if (!SlAiStyleInstance.IsValid()) {
		SlAiStyleInstance = Create();
		FSlateStyleRegistry::RegisterSlateStyle(*SlAiStyleInstance);//Ҫ�˽�ΪʲôҪ����һ����Ҫ����Դ�룬�����Ȳ����˽⡣
	}
}

FName SlAiStyleClass::GetStyleName()
{
	static FName StyleSetName(TEXT("SlAiStyleClass"));//TEXT���ص���һ��FString����
	return StyleSetName;
}

void SlAiStyleClass::shutDown()
{
	FSlateStyleRegistry::UnRegisterSlateStyle(*SlAiStyleInstance);
	ensure(SlAiStyleInstance.IsUnique());
	SlAiStyleInstance.Reset();
}

const ISlateStyle& SlAiStyleClass::Get()
{
	return *SlAiStyleInstance;
}

TSharedRef<class FSlateStyleSet> SlAiStyleClass::Create()
{
	//TSharedRef����ת��Ϊptr��ʱ���ܷ�����
	TSharedRef<FSlateStyleSet> StyleRef = FSlateGameResources::New(SlAiStyleClass::GetStyleName(),"/Game/UI/Style", "/Game/UI/Style");
	//ͨ���������ָ�������Ҳ������C++��ֱ��������ʽ����������������
	StyleRef->Set("MenuItemFont",FSlateFontInfo("Roboto-Regular.ttf",50));
	return StyleRef;
}
