// Fill out your copyright notice in the Description page of Project Settings.


#include "SSlAiGameOptionWidget.h"
#include "SlateOptMacros.h"
#include "SlAiStyleClass.h"
#include "SlAiWidgetStyle.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/Images/SImage.h"
#include "Widgets/Text/STextBlock.h"
#include "Widgets/Layout/SBorder.h"
#include "Widgets/SOverlay.h"
#include "Widgets/SBoxPanel.h"
#include "Widgets/Input/SCheckBox.h"
#include "Widgets/Input/SSlider.h"

#include "SlatePractice/Data/SlAiDataHelper.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SSlAiGameOptionWidget::Construct(const FArguments& InArgs)
{
	//��ȡMenuStyle
	MenuStyle = &SlAiStyleClass::Get().GetWidgetStyle<FSlAiStyle>("BPSlAiMenuStyle");

	//��ȡί��
	ChangeCulture = InArgs._ChangeCulture;
	ChangeVolume = InArgs._ChangeVolume;

	ChildSlot
	[
		SNew(SBox)
		.WidthOverride(500.f)
		.HeightOverride(300.f)
		[
			SNew(SOverlay)
			+SOverlay::Slot()
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Fill)
			[
				SNew(SImage)
				.Image(&MenuStyle->GameOptionBGBrush) 
			]
			+SOverlay::Slot()
				.HAlign(HAlign_Fill)
				.VAlign(VAlign_Fill)
				.Padding(FMargin(50.f))
				[
					SNew(SVerticalBox)
					//��һ��
					+ SVerticalBox::Slot()
					.HAlign(HAlign_Fill)
					.VAlign(VAlign_Fill)
					.FillHeight(1.f)
					[
						SNew(SHorizontalBox)

						+SHorizontalBox::Slot()
						.HAlign(HAlign_Center)
						.VAlign(VAlign_Center)
						.FillWidth(1.f)
						[
							SAssignNew(ZhCheckBox,SCheckBox)
							.OnCheckStateChanged(this,&SSlAiGameOptionWidget::ZhCheckBoxStateChange)
							[
								SNew(STextBlock)
								.Font(MenuStyle->Font_40)
								.ColorAndOpacity(MenuStyle->FontColor_Black)
								.Text(NSLOCTEXT("SlAiMenu","Chinese","Chinese"))
							]
						]

						+ SHorizontalBox::Slot()
						.HAlign(HAlign_Center)
						.VAlign(VAlign_Center)
						.FillWidth(1.f)
						[
							SAssignNew(EnCheckBox, SCheckBox)
							.OnCheckStateChanged(this, &SSlAiGameOptionWidget::EnCheckBoxStateChange)
						[
							SNew(STextBlock)
							.Font(MenuStyle->Font_40)
							.ColorAndOpacity(MenuStyle->FontColor_Black)
							.Text(NSLOCTEXT("SlAiMenu", "English", "English"))
						]
						]
					]
					//�ڶ���
					+ SVerticalBox::Slot()
					.HAlign(HAlign_Fill)
					.VAlign(VAlign_Fill)
					.FillHeight(1.f)
					[
						SNew(SOverlay)
						+SOverlay::Slot()
						.HAlign(HAlign_Left)
						.VAlign(VAlign_Center)
						[
							SNew(STextBlock)
							.Font(MenuStyle->Font_40)
							.ColorAndOpacity(MenuStyle->FontColor_Black)
							.Text(NSLOCTEXT("SlAiMenu","Music","Music"))
						]
						+ SOverlay::Slot()
						.HAlign(HAlign_Center)
						.VAlign(VAlign_Center)
							[
								SNew(SBox)
								.WidthOverride(240.f)
								[
									SNew(SOverlay)
									+SOverlay::Slot()
									.HAlign(HAlign_Fill)
									.VAlign(VAlign_Center)
									.Padding(FMargin(30.f,0.f))
									[
										SNew(SImage)
										.Image(&MenuStyle->SliderBarBrush)
									]
									+SOverlay::Slot()
									.HAlign(HAlign_Fill)
									.VAlign(VAlign_Center)
									[
										SAssignNew(MuSlider,SSlider)
										.Style(&MenuStyle->SliderStyle)
										.OnValueChanged(this, &SSlAiGameOptionWidget::MusicSliderChanged)
									]
								]
							]
						+SOverlay::Slot()
						.HAlign(HAlign_Right)
						.VAlign(VAlign_Center)
						[
							SAssignNew(MuTextBlock,STextBlock)
							.Font(MenuStyle->Font_40)
							.ColorAndOpacity(MenuStyle->FontColor_Black)
						]
					]
					//������
					+ SVerticalBox::Slot()
					.HAlign(HAlign_Fill)
					.VAlign(VAlign_Fill)
					.FillHeight(1.f)
					[
						SNew(SOverlay)
						+ SOverlay::Slot()
						.HAlign(HAlign_Left)
						.VAlign(VAlign_Center)
						[
							SNew(STextBlock)
							.Font(MenuStyle->Font_40)
						.ColorAndOpacity(MenuStyle->FontColor_Black)
						.Text(NSLOCTEXT("SlAiMenu", "Sound", "Sound"))
						]
					+ SOverlay::Slot()
						.HAlign(HAlign_Center)
						.VAlign(VAlign_Center)
						[
							SNew(SBox)
							.WidthOverride(240.f)
						[
							SNew(SOverlay)
							+ SOverlay::Slot()
						.HAlign(HAlign_Fill)
						.VAlign(VAlign_Center)
						.Padding(FMargin(30.f, 0.f))
						[
							SNew(SImage)
							.Image(&MenuStyle->SliderBarBrush)
						]
					+ SOverlay::Slot()
						.HAlign(HAlign_Fill)
						.VAlign(VAlign_Center)
						[
							SAssignNew(SoSlider, SSlider)
							.Style(&MenuStyle->SliderStyle)
						.OnValueChanged(this, &SSlAiGameOptionWidget::SoundSliderChanged)
						]
						]
						]
					+ SOverlay::Slot()
						.HAlign(HAlign_Right)
						.VAlign(VAlign_Center)
						[
							SAssignNew(SoTextBlock, STextBlock)
							.Font(MenuStyle->Font_40)
						.ColorAndOpacity(MenuStyle->FontColor_Black)
						]
					]

				]
		]
	];
	StyleInitialized();

}
void SSlAiGameOptionWidget::StyleInitialized()
{
	//����ZhCheckBox��ʽ
	ZhCheckBox->SetUncheckedImage(&MenuStyle->UnCheckBoxBrush);
	ZhCheckBox->SetUncheckedHoveredImage(&MenuStyle->UnCheckBoxBrush);
	ZhCheckBox->SetUncheckedPressedImage(&MenuStyle->UnCheckBoxBrush);
	ZhCheckBox->SetCheckedImage(&MenuStyle->CheckBoxBrush);
	ZhCheckBox->SetCheckedHoveredImage(&MenuStyle->CheckBoxBrush);
	ZhCheckBox->SetCheckedPressedImage(&MenuStyle->CheckBoxBrush);


	//����EnCheckBox��ʽ
	EnCheckBox->SetUncheckedImage(&MenuStyle->UnCheckBoxBrush);
	EnCheckBox->SetUncheckedHoveredImage(&MenuStyle->UnCheckBoxBrush);
	EnCheckBox->SetUncheckedPressedImage(&MenuStyle->UnCheckBoxBrush);
	EnCheckBox->SetCheckedImage(&MenuStyle->CheckBoxBrush);
	EnCheckBox->SetCheckedHoveredImage(&MenuStyle->CheckBoxBrush);
	EnCheckBox->SetCheckedPressedImage(&MenuStyle->CheckBoxBrush);

	switch (SlAiDataHelper::Get()->CurrentCulture)
	{
	case ECultrueTeam::EN:
		EnCheckBox->SetIsChecked(ECheckBoxState::Checked);
		ZhCheckBox->SetIsChecked(ECheckBoxState::Unchecked);
		break;
	case ECultrueTeam::ZH:
		EnCheckBox->SetIsChecked(ECheckBoxState::Unchecked);
		ZhCheckBox->SetIsChecked(ECheckBoxState::Checked);
		break;
	}

	//���û������ĳ�ʼֵΪ��һ�α����ֵ����Ϊ���������ݴ洢��SlAiDataHelper�ĵ��������С�
	MuSlider->SetValue(SlAiDataHelper::Get()->MusicVolume);
	SoSlider->SetValue(SlAiDataHelper::Get()->SoundVolume);
	MuTextBlock->SetText(FText::FromString(FString::FromInt(FMath::RoundToInt(SlAiDataHelper::Get()->MusicVolume * 100)) + FString("%")));
	SoTextBlock->SetText(FText::FromString(FString::FromInt(FMath::RoundToInt(SlAiDataHelper::Get()->SoundVolume * 100)) + FString("%")));

}
void SSlAiGameOptionWidget::ZhCheckBoxStateChange(ECheckBoxState NewState)
{
	//���ñ�ѡ�еĿ�
	EnCheckBox->SetIsChecked(ECheckBoxState::Unchecked);
	ZhCheckBox->SetIsChecked(ECheckBoxState::Checked);
	//�������ݿ�����ת��Ϊ����
	//SlAiDataHelper::Get()->ChnageLocalizationCulture(ECultrueTeam::ZH);
	ChangeCulture.ExecuteIfBound(ECultrueTeam::ZH);

}
void SSlAiGameOptionWidget::EnCheckBoxStateChange(ECheckBoxState NewState)
{
	//���ñ�ѡ�еĿ�
	EnCheckBox->SetIsChecked(ECheckBoxState::Checked);
	ZhCheckBox->SetIsChecked(ECheckBoxState::Unchecked);
	//�������ݿ�����ת��ΪӢ��
	//SlAiDataHelper::Get()->ChnageLocalizationCulture(ECultrueTeam::EN);
	ChangeCulture.ExecuteIfBound(ECultrueTeam::EN);
}
void SSlAiGameOptionWidget::MusicSliderChanged(float Value)
{
	//��ʾ�ٷֱ�
	MuTextBlock->SetText(FText::FromString(FString::FromInt(FMath::RoundToInt(Value * 100)) + FString("%")));
	//�޸�����
	//SlAiDataHelper::Get()->ResetMenuVolume(Value, -1.f);
	ChangeVolume.ExecuteIfBound(Value, -1.f);
}
void SSlAiGameOptionWidget::SoundSliderChanged(float Value)
{
	//��ʾ�ٷֱ�
	SoTextBlock->SetText(FText::FromString(FString::FromInt(FMath::RoundToInt(Value * 100)) + FString("%")));
	//�޸�����
	//SlAiDataHelper::Get()->ResetMenuVolume(-1.f, Value);
	ChangeVolume.ExecuteIfBound(-1.f, Value);
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION
