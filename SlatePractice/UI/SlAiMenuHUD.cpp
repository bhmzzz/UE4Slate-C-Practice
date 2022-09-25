// Fill out your copyright notice in the Description page of Project Settings.


#include "SlAiMenuHUD.h"
#include "SSlAiMenuHUDWidget.h"
#include "SlateBasics.h"

ASlAiMenuHUD::ASlAiMenuHUD()
{
	//创建MenuHUDWidget并将其AddToViewPort
	if (GEngine && GEngine->GameViewport)//检查视口是否存在
	{
		SAssignNew(MenuHUDWidget, SSlAiMenuHUDWidget);//还有一种创建widget的方法是SNew()
		GEngine->GameViewport->AddViewportWidgetContent(SNew(SWeakWidget).PossiblyNullContent(MenuHUDWidget.ToSharedRef()));//将widget添加到视口
	}
}
