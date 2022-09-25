// Fill out your copyright notice in the Description page of Project Settings.


#include "SSlAiChooseRecordWidget.h"
#include "SlateOptMacros.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/Text/STextBlock.h"
#include "Widgets/SOverlay.h"
#include "Widgets/Input/SEditableTextBox.h"
#include "Widgets/Images/SImage.h"
#include "SlatePractice/Data/SlAiDataHelper.h"
#include "Widgets/Input/STextComboBox.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SSlAiChooseRecordWidget::Construct(const FArguments& InArgs)
{
	//��ȡMenuStyle
	MenuStyle = &SlAiStyleClass::Get().GetWidgetStyle<FSlAiStyle>("BPSlAiMenuStyle");

	//��ʼ�������˵����ݣ�������еĴ浵�������ڶ�ȡ�浵��
	for (TArray<FString>::TIterator It(SlAiDataHelper::Get()->RecordDataList); It; ++It)
	{
		OptionsSource.Add(MakeShareable(new FString(*It)));
	}

	ChildSlot
	[
		SNew(SBox)
		.WidthOverride(500.f)
		.HeightOverride(100.f)
		[
			SNew(SOverlay)
			+ SOverlay::Slot()
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Fill)
		[
			SNew(SImage)
			.Image(&MenuStyle->MenuItemBrush)
		]
	+ SOverlay::Slot()
		.HAlign(HAlign_Left)
		.VAlign(VAlign_Center)
		.Padding(FMargin(20.f, 0.f, 0.f, 0.f))
		[
			SNew(STextBlock)
			.Font(MenuStyle->Font_40)
		.Text(NSLOCTEXT("SlAiMenu", "NewGame", "NewGame"))
		]
	+ SOverlay::Slot()
		.HAlign(HAlign_Right)
		.VAlign(VAlign_Center)
		.Padding(FMargin(0.f, 0.f, 20.f, 0.f))
		[
			SNew(SBox)
			.WidthOverride(300.f)
		.HeightOverride(60.f)
		[
			SAssignNew(RecordComboBox, STextComboBox)
			.Font(MenuStyle->Font_30)
		.OptionsSource(&OptionsSource)//�����˵�������
		]
		]
		]
	];

	//����Ĭ�ϵ�ѡ������˵�һ��ʼĬ��ѡ�е�һ��
	RecordComboBox->SetSelectedItem(OptionsSource[0]);

}

END_SLATE_FUNCTION_BUILD_OPTIMIZATION

void SSlAiChooseRecordWidget::UpdateRecordName()
{
	//�޸Ĵ浵��
	SlAiDataHelper::Get()->RecordName = *RecordComboBox->GetSelectedItem().Get();
}

