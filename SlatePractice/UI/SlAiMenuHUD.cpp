// Fill out your copyright notice in the Description page of Project Settings.


#include "SlAiMenuHUD.h"
#include "SSlAiMenuHUDWidget.h"
#include "SlateBasics.h"

ASlAiMenuHUD::ASlAiMenuHUD()
{
	//����MenuHUDWidget������AddToViewPort
	if (GEngine && GEngine->GameViewport)//����ӿ��Ƿ����
	{
		SAssignNew(MenuHUDWidget, SSlAiMenuHUDWidget);//����һ�ִ���widget�ķ�����SNew()
		GEngine->GameViewport->AddViewportWidgetContent(SNew(SWeakWidget).PossiblyNullContent(MenuHUDWidget.ToSharedRef()));//��widget��ӵ��ӿ�
	}
}
