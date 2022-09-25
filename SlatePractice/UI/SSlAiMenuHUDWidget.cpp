// Fill out your copyright notice in the Description page of Project Settings.


#include "SSlAiMenuHUDWidget.h"
#include "SlateOptMacros.h"
#include "Widgets/Input/SButton.h"
#include "Widgets/Images/SImage.h"
#include "SlAiStyleClass.h"
#include "SlAiWidgetStyle.h"
#include "Widgets/Layout/SDPIScaler.h"
#include "SSlAiMenuWidget.h"

//Widget������ݱ�д�൱�ھ��Ƕ�UMG��widget���б�д
BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SSlAiMenuHUDWidget::Construct(const FArguments& InArgs)
{
	//��ȡ�༭����MenuStyle
	MenuStyle = &SlAiStyleClass::Get().GetWidgetStyle<FSlAiStyle>("BPSlAiMenuStyle");
	//�����Ź��򷽷�
	UIScaler.Bind(this, &SSlAiMenuHUDWidget::GetUIScaler);

	ChildSlot//�൱��UMG��CanvasPannel�ܹ����ɲ㼶�ṹ,�����������ص������
		[
			// Populate the widget
			//SNew()����һ��UI���ֻ��Ҫ�ڲ����м�����������������ΪTSharedRef��
			SNew(SDPIScaler)
			.DPIScale(UIScaler)//֮�����·���ӵ������������������UIScaler��ֵ������
	[
			SNew(SOverlay)
			+ SOverlay::Slot() //���һ��������Թ���һ������������������Image
		.HAlign(HAlign_Fill) //ˮƽ����
		.VAlign(VAlign_Fill) //��ֱ����
		//.Padding(FMargin(30.f)) //������Ե����Ϊ30
		[
			SNew(SImage)//��Image������һ����ˢ
			.Image(&MenuStyle->MenuHUDBackgroundBrush)  //MenuHUDBackgroundBrush����
		]
	+ SOverlay::Slot()
		.HAlign(HAlign_Center)
		.VAlign(VAlign_Center)
		/*.Expose(ImageSlot)*/
		[
			SAssignNew(MenuWidget,SSlAiMenuWidget)
		]
	/*+ SOverlay::Slot()
		.HAlign(HAlign_Left)
		.VAlign(VAlign_Top)
		[
			SNew(SButton)
			.OnClicked(this, &SSlAiMenuHUDWidget::OnClick)
		]*/
	]
	];
	
}
float SSlAiMenuHUDWidget::GetUIScaler() const
{
	return GetViewportSize().Y / 1080.f;
}
FVector2D SSlAiMenuHUDWidget::GetViewportSize() const
{
	FVector2D Result(1920, 1080);
	if (GEngine && GEngine->GameViewport)
		GEngine->GameViewport->GetViewportSize(Result);
	return Result;
}
//FReply SSlAiMenuHUDWidget::OnClick()
//{
//	ImageSlot->HAlign(HAlign_Right).VAlign(VAlign_Bottom);
//	return FReply::Handled();
//}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION
