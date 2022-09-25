// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SOverlay.h"
#include "Widgets/SCompoundWidget.h"

/**
 * 
 */
class SLATEPRACTICE_API SSlAiMenuHUDWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SSlAiMenuHUDWidget)
	{}
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

private:
	//��UIScaler�ĺ���
	float GetUIScaler() const;
	//��ȡ��Ļ�ߴ�
	FVector2D GetViewportSize() const;

	/*FReply OnClick();*/

private:
	//��ȡMenu��ʽ
	const struct FSlAiStyle* MenuStyle;

	//DPI����ϵ��
	TAttribute<float> UIScaler;
	////��ȡ�˵�Image��slot
	//SOverlay::FOverlaySlot* ImageSlot;

	//�˵�ָ��
	TSharedPtr<class SSlAiMenuWidget> MenuWidget;

};
