// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SlateBasics.h" 

/**
 * 
 */
//该类的作用为获取编辑器中的对应样式，主界面UI的widget作为一个单例被调用
class SLATEPRACTICE_API SlAiStyleClass
{
public:
	static void Initialze();

	static FName GetStyleName();

	static void shutDown();

	static const ISlateStyle& Get();

private:
	static TSharedRef<class FSlateStyleSet> Create();//用于注册样式

	static TSharedPtr<FSlateStyleSet> SlAiStyleInstance;
};
