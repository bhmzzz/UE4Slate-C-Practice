// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

class FSlatePractice : public FDefaultGameModuleImpl
{
public:
	//��ʼʱ��ִ��,ģ�����ʱ
	virtual void StartupModule() override;
	//����ʱ��ִ��,ģ��ж��ʱ
	virtual void ShutdownModule() override;
};

