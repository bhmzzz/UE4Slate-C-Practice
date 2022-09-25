// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SlateBasics.h" 

/**
 * 
 */
//���������Ϊ��ȡ�༭���еĶ�Ӧ��ʽ��������UI��widget��Ϊһ������������
class SLATEPRACTICE_API SlAiStyleClass
{
public:
	static void Initialze();

	static FName GetStyleName();

	static void shutDown();

	static const ISlateStyle& Get();

private:
	static TSharedRef<class FSlateStyleSet> Create();//����ע����ʽ

	static TSharedPtr<FSlateStyleSet> SlAiStyleInstance;
};
