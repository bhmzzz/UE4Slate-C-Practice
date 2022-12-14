// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include  "SlatePractice/Data/SlAiTypes.h"
#include "Widgets/SCompoundWidget.h"

/**
 * 
 */

class SCheckBox;
class SSlider;
class STextBlock;

//修改中英文委托
DECLARE_DELEGATE_OneParam(FChangeCulture, const ECultrueTeam)
//修改音量的委托
DECLARE_DELEGATE_TwoParams(FChangeVolume, const float, const float)

class SLATEPRACTICE_API SSlAiGameOptionWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SSlAiGameOptionWidget)
	{}

	SLATE_EVENT(FChangeCulture, ChangeCulture)
	SLATE_EVENT(FChangeVolume, ChangeVolume)

	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

private:

	//统一设置样式
	void StyleInitialized();

	//中文CheckBox事件
	void ZhCheckBoxStateChange(ECheckBoxState NewState);
	//英文CheckBox事件
	void EnCheckBoxStateChange(ECheckBoxState NewState);

	//音量变化事件
	void MusicSliderChanged(float Value);
	void SoundSliderChanged(float Value);

private:
	//获取MenuStyle
	const struct FSlAiStyle* MenuStyle;

	//获取CheckBox指针
	TSharedPtr<SCheckBox> EnCheckBox;
	TSharedPtr<SCheckBox> ZhCheckBox;

	//两个进度条
	TSharedPtr<SSlider> MuSlider;//背景音乐
	TSharedPtr<SSlider> SoSlider;//音效

	//进度条百分比
	TSharedPtr<STextBlock> MuTextBlock;
	TSharedPtr<STextBlock> SoTextBlock;

	//委托变量
	FChangeCulture ChangeCulture;
	FChangeVolume ChangeVolume;
};
