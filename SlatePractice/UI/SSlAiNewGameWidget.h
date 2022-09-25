// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SlatePractice/UI/SlAiSTyleClass.h"
#include "SlatePractice/UI/SlAiWidgetStyle.h"
#include "Widgets/SCompoundWidget.h"

class SEditableTextBox;

/**
 * 
 */
class SLATEPRACTICE_API SSlAiNewGameWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SSlAiNewGameWidget)
	{}
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

	//是否可以进入游戏
	bool AllowEnterGame();

private:
	//获取MenuStyle
	const struct FSlAiStyle* MenuStyle;

	//输入框指针
	TSharedPtr<SEditableTextBox> EditableTextBox;
};
