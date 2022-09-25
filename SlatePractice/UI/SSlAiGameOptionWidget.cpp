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
	//获取MenuStyle
	MenuStyle = &SlAiStyleClass::Get().GetWidgetStyle<FSlAiStyle>("BPSlAiMenuStyle");

	//获取委托
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
					//第一行
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
					//第二行
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
					//第三行
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
	//设置ZhCheckBox样式
	ZhCheckBox->SetUncheckedImage(&MenuStyle->UnCheckBoxBrush);
	ZhCheckBox->SetUncheckedHoveredImage(&MenuStyle->UnCheckBoxBrush);
	ZhCheckBox->SetUncheckedPressedImage(&MenuStyle->UnCheckBoxBrush);
	ZhCheckBox->SetCheckedImage(&MenuStyle->CheckBoxBrush);
	ZhCheckBox->SetCheckedHoveredImage(&MenuStyle->CheckBoxBrush);
	ZhCheckBox->SetCheckedPressedImage(&MenuStyle->CheckBoxBrush);


	//设置EnCheckBox样式
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

	//设置滑动条的初始值为上一次保存的值，作为单例的数据存储在SlAiDataHelper的单例对象中。
	MuSlider->SetValue(SlAiDataHelper::Get()->MusicVolume);
	SoSlider->SetValue(SlAiDataHelper::Get()->SoundVolume);
	MuTextBlock->SetText(FText::FromString(FString::FromInt(FMath::RoundToInt(SlAiDataHelper::Get()->MusicVolume * 100)) + FString("%")));
	SoTextBlock->SetText(FText::FromString(FString::FromInt(FMath::RoundToInt(SlAiDataHelper::Get()->SoundVolume * 100)) + FString("%")));

}
void SSlAiGameOptionWidget::ZhCheckBoxStateChange(ECheckBoxState NewState)
{
	//设置被选中的框
	EnCheckBox->SetIsChecked(ECheckBoxState::Unchecked);
	ZhCheckBox->SetIsChecked(ECheckBoxState::Checked);
	//告诉数据控制类转换为中文
	//SlAiDataHelper::Get()->ChnageLocalizationCulture(ECultrueTeam::ZH);
	ChangeCulture.ExecuteIfBound(ECultrueTeam::ZH);

}
void SSlAiGameOptionWidget::EnCheckBoxStateChange(ECheckBoxState NewState)
{
	//设置被选中的框
	EnCheckBox->SetIsChecked(ECheckBoxState::Checked);
	ZhCheckBox->SetIsChecked(ECheckBoxState::Unchecked);
	//告诉数据控制类转换为英文
	//SlAiDataHelper::Get()->ChnageLocalizationCulture(ECultrueTeam::EN);
	ChangeCulture.ExecuteIfBound(ECultrueTeam::EN);
}
void SSlAiGameOptionWidget::MusicSliderChanged(float Value)
{
	//显示百分比
	MuTextBlock->SetText(FText::FromString(FString::FromInt(FMath::RoundToInt(Value * 100)) + FString("%")));
	//修改音量
	//SlAiDataHelper::Get()->ResetMenuVolume(Value, -1.f);
	ChangeVolume.ExecuteIfBound(Value, -1.f);
}
void SSlAiGameOptionWidget::SoundSliderChanged(float Value)
{
	//显示百分比
	SoTextBlock->SetText(FText::FromString(FString::FromInt(FMath::RoundToInt(Value * 100)) + FString("%")));
	//修改音量
	//SlAiDataHelper::Get()->ResetMenuVolume(-1.f, Value);
	ChangeVolume.ExecuteIfBound(-1.f, Value);
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION
