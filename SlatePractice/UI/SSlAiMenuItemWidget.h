// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "SlatePractice/Data/SlAiTypes.h"
#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"


DECLARE_DELEGATE_OneParam(FItemClicked, const EMenuItem::Type)
/**
 * 
 */

class SLATEPRACTICE_API SSlAiMenuItemWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SSlAiMenuItemWidget)
	{}
	SLATE_ATTRIBUTE(FText, ItemText)

		SLATE_EVENT(FItemClicked, OnClicked)

	SLATE_ATTRIBUTE(EMenuItem::Type, ItemType)

	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);


	//重写组件的OnMouseButtonDown方法
	virtual FReply OnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;
	//重写组件的OnMouseButtonUp方法
	virtual FReply OnMouseButtonUp(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;
	//鼠标离开
	virtual void OnMouseLeave(const FPointerEvent& MouseEvent) override;


private:
	//获取颜色
	FSlateColor GetTintColor() const;

private:

	//获取MenuStyle
	const struct FSlAiStyle* MenuStyle;
	//按下事件委托
	FItemClicked OnClicked;
	//保存按钮类型
	EMenuItem::Type ItemType;

	//按钮是否已经按下
	bool IsMouseButtonDown;
};
