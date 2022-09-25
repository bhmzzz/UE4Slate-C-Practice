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

	//获取MenuStyle
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
						.HintText(NSLOCTEXT("SlAiMenu","RecordNameHint","Input Record Name!"))//输入框什么也没输入的时候显示
						.Font(MenuStyle->Font_30)
					]
				]
		]
	];

}
bool SSlAiNewGameWidget::AllowEnterGame()
{
	//获取输入的新存档名
	FText InputText = EditableTextBox->GetText();

	//文字是否为空
	if (InputText.ToString().IsEmpty())
		return false;
	//查询是否存在文档
	for (TArray<FString>::TIterator It(SlAiDataHelper::Get()->RecordDataList); It; ++It)
	{
		if ((*It).Equals(InputText.ToString()))
		{
			//设置输入框为空，存档名重复
			EditableTextBox->SetText(FText::FromString(""));
			//修改Hint存档名重复
			EditableTextBox->SetHintText(NSLOCTEXT("SlAiMenu", "NameRepeateHint", "Record Name Repeated!"));
			
			return false;
		}
	}
	//保存新的存档名
	SlAiDataHelper::Get()->RecordName = InputText.ToString();
	return true;
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION
