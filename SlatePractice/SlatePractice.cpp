// Copyright Epic Games, Inc. All Rights Reserved.

#include "SlatePractice.h"
#include "Modules/ModuleManager.h"
#include "UI/SlAiStyleClass.h"

void FSlatePractice::StartupModule()
{
	//初始化样式
	FSlateStyleRegistry::UnRegisterSlateStyle(SlAiStyleClass::GetStyleName());//先取消注册避免重复注册
	//初始化注册样式
	SlAiStyleClass::Initialze();
}

void FSlatePractice::ShutdownModule()
{
	//注销，解除注册
	SlAiStyleClass::shutDown();
}

//初始化游戏模组
IMPLEMENT_PRIMARY_GAME_MODULE(FSlatePractice, SlatePractice, "SlatePractice");
