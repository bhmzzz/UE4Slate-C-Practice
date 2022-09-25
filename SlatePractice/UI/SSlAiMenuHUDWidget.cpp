// Fill out your copyright notice in the Description page of Project Settings.


#include "SSlAiMenuHUDWidget.h"
#include "SlateOptMacros.h"
#include "Widgets/Input/SButton.h"
#include "Widgets/Images/SImage.h"
#include "SlAiStyleClass.h"
#include "SlAiWidgetStyle.h"
#include "Widgets/Layout/SDPIScaler.h"
#include "SSlAiMenuWidget.h"

//Widget类的内容编写相当于就是对UMG的widget进行编写
BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SSlAiMenuHUDWidget::Construct(const FArguments& InArgs)
{
	//获取编辑器的MenuStyle
	MenuStyle = &SlAiStyleClass::Get().GetWidgetStyle<FSlAiStyle>("BPSlAiMenuStyle");
	//绑定缩放规则方法
	UIScaler.Bind(this, &SSlAiMenuHUDWidget::GetUIScaler);

	ChildSlot//相当于UMG的CanvasPannel能够容纳层级结构,中括号是重载的运算符
		[
			// Populate the widget
			//SNew()产生一个UI组件只需要在参数中加入类名，返回类型为TSharedRef。
			SNew(SDPIScaler)
			.DPIScale(UIScaler)//之后在下方添加的所有组件都会根据这个UIScaler的值来缩放
	[
			SNew(SOverlay)
			+ SOverlay::Slot() //添加一个插槽用以挂载一个物体组件例如下面的Image
		.HAlign(HAlign_Fill) //水平铺满
		.VAlign(VAlign_Fill) //垂直铺满
		//.Padding(FMargin(30.f)) //各处边缘距离为30
		[
			SNew(SImage)//给Image组件添加一个笔刷
			.Image(&MenuStyle->MenuHUDBackgroundBrush)  //MenuHUDBackgroundBrush错误
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
