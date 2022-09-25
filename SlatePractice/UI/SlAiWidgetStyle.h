// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Styling/SlateWidgetStyle.h"
#include "Styling/SlateWidgetStyleContainerBase.h"
#include "Styling/SlateBrush.h"
#include "Fonts/SlateFontInfo.h"
#include "Sound/SlateSound.h"
#include "SlAiWidgetStyle.generated.h"

/**
 * 
 */
USTRUCT()
struct SLATEPRACTICE_API FSlAiStyle : public FSlateWidgetStyle
{
	GENERATED_USTRUCT_BODY()

	FSlAiStyle();
	virtual ~FSlAiStyle();

	// FSlateWidgetStyle
	virtual void GetResources(TArray<const FSlateBrush*>& OutBrushes) const override;
	static const FName TypeName;
	virtual const FName GetTypeName() const override { return TypeName; };
	static const FSlAiStyle& GetDefault();

	//定义笔刷用于Image填充
	UPROPERTY(EditAnywhere, Category = MenuHUD)
		FSlateBrush MenuHUDBackgroundBrush;

	//定义笔刷用于MenuImage填充
	UPROPERTY(EditAnywhere, Category = Menu)
		FSlateBrush MenuBackgroundBrush;

	//定义Menu左图标的Brush
	UPROPERTY(EditAnywhere, Category = Menu)
		FSlateBrush LeftIconBrush;

	//定义Menu右图标的Brush
	UPROPERTY(EditAnywhere, Category = Menu)
		FSlateBrush RightIconBrush;

	//定义Menu标题Border的Brush
	UPROPERTY(EditAnywhere, Category = Menu)
		FSlateBrush TitleBorderBrush;

	//定义MenuItem的Brush
	UPROPERTY(EditAnywhere, Category = MenuItem)
		FSlateBrush MenuItemBrush;


	//60号字体
	UPROPERTY(EditAnywhere, Category = Common)
		FSlateFontInfo Font_60;

	//40号字体
	UPROPERTY(EditAnywhere, Category = Common)
		FSlateFontInfo Font_40;

	//30号字体
	UPROPERTY(EditAnywhere, Category = Common)
		FSlateFontInfo Font_30;

	//字体白色
	UPROPERTY(EditAnywhere, Category = Common)
		FLinearColor FontColor_White;

	//字体黑色
	UPROPERTY(EditAnywhere, Category = Common)
		FLinearColor FontColor_Black;

	//定义GameSet的Brush
	UPROPERTY(EditAnywhere, Category = GameOption)
		FSlateBrush GameOptionBGBrush;

	//定义CheckBox的Brush
	UPROPERTY(EditAnywhere, Category = GameOption)
		FSlateBrush CheckBoxBrush;

	//定义UnCheckBox的Brush
	UPROPERTY(EditAnywhere, Category = GameOption)
		FSlateBrush UnCheckBoxBrush;

	//定义Slider的背景Brush
	UPROPERTY(EditAnywhere, Category = GameOption)
		FSlateBrush SliderBarBrush;

	//指定Slider的样式
	UPROPERTY(EditAnywhere, Category = GameOption)
		FSliderStyle SliderStyle;

	//开始游戏声音
	UPROPERTY(EditAnywhere, Category = Sound)
		FSlateSound StartGameSound;

	//结束游戏声音
	UPROPERTY(EditAnywhere, Category = Sound)
		FSlateSound ExitGameSound;

	//转换按钮声音
	UPROPERTY(EditAnywhere, Category = Sound)
		FSlateSound MenuItemChangeSound;

	//Menu背景声音
	UPROPERTY(EditAnywhere, Category = Sound)
		FSlateSound MenuBackgroundMusic;

};

/**
 */
UCLASS(hidecategories=Object, MinimalAPI)
class USlAiWidgetStyle : public USlateWidgetStyleContainerBase
{
	GENERATED_BODY()

public:
	/** The actual data describing the widget appearance. */
	UPROPERTY(Category=Appearance, EditAnywhere, meta=(ShowOnlyInnerProperties))
	FSlAiStyle WidgetStyle;

	virtual const struct FSlateWidgetStyle* const GetStyle() const override
	{
		return static_cast< const struct FSlateWidgetStyle* >( &WidgetStyle );
	}
};
