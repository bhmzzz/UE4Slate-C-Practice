// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

class FSlatePractice : public FDefaultGameModuleImpl
{
public:
	//开始时会执行,模组加载时
	virtual void StartupModule() override;
	//结束时会执行,模组卸载时
	virtual void ShutdownModule() override;
};

