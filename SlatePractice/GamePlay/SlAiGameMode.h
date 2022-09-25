// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SlAiGameMode.generated.h"

/**
 * 
 */
UCLASS()
class SLATEPRACTICE_API ASlAiGameMode : public AGameModeBase
{
	GENERATED_BODY()
public:
	ASlAiGameMode();
protected:
	virtual void BeginPlay() override;


};
