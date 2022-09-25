// Fill out your copyright notice in the Description page of Project Settings.


#include "SlAiMenuController.h"

ASlAiMenuController::ASlAiMenuController()
{
	bShowMouseCursor = true;
}

void ASlAiMenuController::BeginPlay()
{
	Super::BeginPlay();

	//设置输入模式
	FInputModeUIOnly InputMode;//定义输入模式
	InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::LockAlways);//在UI界面时鼠标锁在视口中
	SetInputMode(InputMode);//设置输入模式
}
