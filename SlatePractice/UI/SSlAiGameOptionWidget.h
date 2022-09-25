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

//�޸���Ӣ��ί��
DECLARE_DELEGATE_OneParam(FChangeCulture, const ECultrueTeam)
//�޸�������ί��
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

	//ͳһ������ʽ
	void StyleInitialized();

	//����CheckBox�¼�
	void ZhCheckBoxStateChange(ECheckBoxState NewState);
	//Ӣ��CheckBox�¼�
	void EnCheckBoxStateChange(ECheckBoxState NewState);

	//�����仯�¼�
	void MusicSliderChanged(float Value);
	void SoundSliderChanged(float Value);

private:
	//��ȡMenuStyle
	const struct FSlAiStyle* MenuStyle;

	//��ȡCheckBoxָ��
	TSharedPtr<SCheckBox> EnCheckBox;
	TSharedPtr<SCheckBox> ZhCheckBox;

	//����������
	TSharedPtr<SSlider> MuSlider;//��������
	TSharedPtr<SSlider> SoSlider;//��Ч

	//�������ٷֱ�
	TSharedPtr<STextBlock> MuTextBlock;
	TSharedPtr<STextBlock> SoTextBlock;

	//ί�б���
	FChangeCulture ChangeCulture;
	FChangeVolume ChangeVolume;
};