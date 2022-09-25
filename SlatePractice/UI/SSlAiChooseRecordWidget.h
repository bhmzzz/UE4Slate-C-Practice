// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SlatePractice/UI/SlAiSTyleClass.h"
#include "SlatePractice/UI/SlAiWidgetStyle.h"
#include "Widgets/SCompoundWidget.h"

/**
 * 
 */

class STextComboBox;

class SLATEPRACTICE_API SSlAiChooseRecordWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SSlAiChooseRecordWidget)
	{}
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

	//���´浵��
	void UpdateRecordName();

private:
	//��ȡMenuStyle
	const struct FSlAiStyle* MenuStyle;

	//�����˵�
	TSharedPtr<STextComboBox> RecordComboBox;

	//�ַ�ָ������
	TArray<TSharedPtr<FString> > OptionsSource;
};
