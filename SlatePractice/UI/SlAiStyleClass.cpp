// Fill out your copyright notice in the Description page of Project Settings.


#include "SlAiStyleClass.h"
#include "Slate/SlateGameResources.h"

TSharedPtr<FSlateStyleSet> SlAiStyleClass::SlAiStyleInstance = NULL;//初始化

void SlAiStyleClass::Initialze()
{
	//如果单例不存在就构建然后注册进游戏
	if (!SlAiStyleInstance.IsValid()) {
		SlAiStyleInstance = Create();
		FSlateStyleRegistry::RegisterSlateStyle(*SlAiStyleInstance);//要了解为什么要有这一步需要翻看源码，现在先不做了解。
	}
}

FName SlAiStyleClass::GetStyleName()
{
	static FName StyleSetName(TEXT("SlAiStyleClass"));//TEXT返回的是一个FString类型
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
	//TSharedRef可以转换为ptr当时不能反过来
	TSharedRef<FSlateStyleSet> StyleRef = FSlateGameResources::New(SlAiStyleClass::GetStyleName(),"/Game/UI/Style", "/Game/UI/Style");
	//通过这个共享指针的引用也可以在C++中直接设置样式例如下面设置字体
	StyleRef->Set("MenuItemFont",FSlateFontInfo("Roboto-Regular.ttf",50));
	return StyleRef;
}
