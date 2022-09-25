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

	//更新存档名
	void UpdateRecordName();

private:
	//获取MenuStyle
	const struct FSlAiStyle* MenuStyle;

	//下拉菜单
	TSharedPtr<STextComboBox> RecordComboBox;

	//字符指针数组
	TArray<TSharedPtr<FString> > OptionsSource;
};
