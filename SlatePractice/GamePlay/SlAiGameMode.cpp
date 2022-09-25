// Fill out your copyright notice in the Description page of Project Settings.


#include "SlAiGameMode.h"
#include "SlatePractice/Data/SlAiDataHelper.h"
#include "SlatePractice/Common/SlAiHelper.h"
#include "SlAiGameInstance.h"
#include "Kismet/GamePlayStatics.h"

ASlAiGameMode::ASlAiGameMode()
{
}

void ASlAiGameMode::BeginPlay()
{
	SlAiHelperNS::Debug(FString("DataHandle : ") + SlAiDataHelper::Get()->RecordName, 30.f);
	SlAiHelperNS::Debug( FString("GameInstance :") +
	Cast<USlAiGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()))->GameName, 30.f);
}
