// Copyright Epic Games, Inc. All Rights Reserved.

#include "SlatePractice.h"
#include "Modules/ModuleManager.h"
#include "UI/SlAiStyleClass.h"

void FSlatePractice::StartupModule()
{
	//��ʼ����ʽ
	FSlateStyleRegistry::UnRegisterSlateStyle(SlAiStyleClass::GetStyleName());//��ȡ��ע������ظ�ע��
	//��ʼ��ע����ʽ
	SlAiStyleClass::Initialze();
}

void FSlatePractice::ShutdownModule()
{
	//ע�������ע��
	SlAiStyleClass::shutDown();
}

//��ʼ����Ϸģ��
IMPLEMENT_PRIMARY_GAME_MODULE(FSlatePractice, SlatePractice, "SlatePractice");
