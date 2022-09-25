// Fill out your copyright notice in the Description page of Project Settings.


#include "SSlAiNewGameWidget.h"
#include "SlateOptMacros.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/Text/STextBlock.h"
#include "Widgets/SOverlay.h"
#include "Widgets/Input/SEditableTextBox.h"
#include "Widgets/Images/SImage.h"
#include "SlatePractice/Data/SlAiDataHelper.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SSlAiNewGameWidget::Construct(const FArguments& InArgs)
{

	//��ȡMenuStyle
	MenuStyle = &SlAiStyleClass::Get().GetWidgetStyle<FSlAiStyle>("BPSlAiMenuStyle");


	ChildSlot
	[
		SNew(SBox)
		.WidthOverride(500.f)
		.HeightOverride(100.f)
		[
			SNew(SOverlay)
			+SOverlay::Slot()
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			[
				SNew(SImage)
				.Image(&MenuStyle->MenuItemBrush)
			]
			+SOverlay::Slot()
				.HAlign(HAlign_Left)
				.VAlign(VAlign_Center)
				.Padding(FMargin(20.f,0.f,0.f,0.f))
				[
					SNew(STextBlock)
					.Font(MenuStyle->Font_40)
				.Text(NSLOCTEXT("SlAiMenu","NewGame","NewGame"))
				]
			+SOverlay::Slot()
				.HAlign(HAlign_Right)
				.VAlign(VAlign_Center)
				.Padding(FMargin(0.f,0.f,20.f,0.f))
				[
					SNew(SBox)
					.WidthOverride(300.f)
				.HeightOverride(60.f)
					[
						SAssignNew(EditableTextBox, SEditableTextBox)
						.HintText(NSLOCTEXT("SlAiMenu","RecordNameHint","Input Record Name!"))//�����ʲôҲû�����ʱ����ʾ
						.Font(MenuStyle->Font_30)
					]
				]
		]
	];

}
bool SSlAiNewGameWidget::AllowEnterGame()
{
	//��ȡ������´浵��
	FText InputText = EditableTextBox->GetText();

	//�����Ƿ�Ϊ��
	if (InputText.ToString().IsEmpty())
		return false;
	//��ѯ�Ƿ�����ĵ�
	for (TArray<FString>::TIterator It(SlAiDataHelper::Get()->RecordDataList); It; ++It)
	{
		if ((*It).Equals(InputText.ToString()))
		{
			//���������Ϊ�գ��浵���ظ�
			EditableTextBox->SetText(FText::FromString(""));
			//�޸�Hint�浵���ظ�
			EditableTextBox->SetHintText(NSLOCTEXT("SlAiMenu", "NameRepeateHint", "Record Name Repeated!"));
			
			return false;
		}
	}
	//�����µĴ浵��
	SlAiDataHelper::Get()->RecordName = InputText.ToString();
	return true;
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION
