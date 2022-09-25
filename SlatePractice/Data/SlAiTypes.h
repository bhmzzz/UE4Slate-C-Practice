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

//Menu�İ�ť����
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

//Menu��������
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

//Menu����״̬��ö��
namespace EMenuAnim
{
	enum Type
	{
		Stop,  //ֹͣ����
		Close, //�ر�Menu
		Open   //��Menu
	};
}

class SLATEPRACTICE_API SlAiTypes
{
public:
	
};
