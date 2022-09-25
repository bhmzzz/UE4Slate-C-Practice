// Fill out your copyright notice in the Description page of Project Settings.


#include "SlAiMenuGameMode.h"
#include "SlAiMenuController.h"
#include "SlatePractice/UI/SlAiMenuHUD.h"
#include "SlAiGameInstance.h"
#include "Kismet/GamePlayStatics.h"


ASlAiMenuGameMode::ASlAiMenuGameMode()
{
	PlayerControllerClass = ASlAiMenuController::StaticClass();
	HUDClass = ASlAiMenuHUD::StaticClass();
}

void ASlAiMenuGameMode::BeginPlay()
{
	Cast<USlAiGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()))->GameName = FString("SlatePractice");
}
