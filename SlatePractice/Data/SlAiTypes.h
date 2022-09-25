// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */

UENUM()
enum class ECultrueTeam : uint8 {
	EN = 0,
	ZH
};

//Menu的按钮类型
namespace EMenuItem
{
	enum Type
	{
		None,
		StartGame,
		QuitGame,
		NewGame,
		NewGameGoBack,
		LoadRecord,
		StartGameGoBack,
		GameOption,
		GameOptionGoBack,
		ChooseRecordGoBack,
		EnterGame,
		EnterRecord
	};
}

//Menu界面类型
namespace EMenuType
{
	enum Type {
		None,
		MainMenu,
		StartGame,
		GameOption,
		NewGame,
		ChooseRecord
	};
}

//Menu动画状态的枚举
namespace EMenuAnim
{
	enum Type
	{
		Stop,  //停止动画
		Close, //关闭Menu
		Open   //打开Menu
	};
}

class SLATEPRACTICE_API SlAiTypes
{
public:
	
};
