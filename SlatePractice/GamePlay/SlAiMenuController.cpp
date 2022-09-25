// Fill out your copyright notice in the Description page of Project Settings.


#include "SlAiMenuController.h"

ASlAiMenuController::ASlAiMenuController()
{
	bShowMouseCursor = true;
}

void ASlAiMenuController::BeginPlay()
{
	Super::BeginPlay();

	//��������ģʽ
	FInputModeUIOnly InputMode;//��������ģʽ
	InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::LockAlways);//��UI����ʱ��������ӿ���
	SetInputMode(InputMode);//��������ģʽ
}
