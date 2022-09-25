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

	//�����ˢ����Image���
	UPROPERTY(EditAnywhere, Category = MenuHUD)
		FSlateBrush MenuHUDBackgroundBrush;

	//�����ˢ����MenuImage���
	UPROPERTY(EditAnywhere, Category = Menu)
		FSlateBrush MenuBackgroundBrush;

	//����Menu��ͼ���Brush
	UPROPERTY(EditAnywhere, Category = Menu)
		FSlateBrush LeftIconBrush;

	//����Menu��ͼ���Brush
	UPROPERTY(EditAnywhere, Category = Menu)
		FSlateBrush RightIconBrush;

	//����Menu����Border��Brush
	UPROPERTY(EditAnywhere, Category = Menu)
		FSlateBrush TitleBorderBrush;

	//����MenuItem��Brush
	UPROPERTY(EditAnywhere, Category = MenuItem)
		FSlateBrush MenuItemBrush;


	//60������
	UPROPERTY(EditAnywhere, Category = Common)
		FSlateFontInfo Font_60;

	//40������
	UPROPERTY(EditAnywhere, Category = Common)
		FSlateFontInfo Font_40;

	//30������
	UPROPERTY(EditAnywhere, Category = Common)
		FSlateFontInfo Font_30;

	//�����ɫ
	UPROPERTY(EditAnywhere, Category = Common)
		FLinearColor FontColor_White;

	//�����ɫ
	UPROPERTY(EditAnywhere, Category = Common)
		FLinearColor FontColor_Black;

	//����GameSet��Brush
	UPROPERTY(EditAnywhere, Category = GameOption)
		FSlateBrush GameOptionBGBrush;

	//����CheckBox��Brush
	UPROPERTY(EditAnywhere, Category = GameOption)
		FSlateBrush CheckBoxBrush;

	//����UnCheckBox��Brush
	UPROPERTY(EditAnywhere, Category = GameOption)
		FSlateBrush UnCheckBoxBrush;

	//����Slider�ı���Brush
	UPROPERTY(EditAnywhere, Category = GameOption)
		FSlateBrush SliderBarBrush;

	//ָ��Slider����ʽ
	UPROPERTY(EditAnywhere, Category = GameOption)
		FSliderStyle SliderStyle;

	//��ʼ��Ϸ����
	UPROPERTY(EditAnywhere, Category = Sound)
		FSlateSound StartGameSound;

	//������Ϸ����
	UPROPERTY(EditAnywhere, Category = Sound)
		FSlateSound ExitGameSound;

	//ת����ť����
	UPROPERTY(EditAnywhere, Category = Sound)
		FSlateSound MenuItemChangeSound;

	//Menu��������
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
