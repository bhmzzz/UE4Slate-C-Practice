// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "SlAiGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class SLATEPRACTICE_API USlAiGameInstance : public UGameInstance
{
	GENERATED_BODY()
public:

	virtual void Init() override;

	UPROPERTY(VisibleAnyWhere, Category = "SlAi")
		FString GameName;
	
};
