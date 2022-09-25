// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SlatePractice/Data/SlAiTypes.h"
#include "Widgets/SCompoundWidget.h"

/**
 * 
 */

class SBox;
class STextBlock;
class SVerticalBox;
struct MenuGroup;
class SSlAiGameOptionWidget;
class SSlAiNewGameWidget;
class SSlAiChooseRecordWidget;

class SLATEPRACTICE_API SSlAiMenuWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SSlAiMenuWidget)
	{}

	SLATE_END_ARGS()



	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

	//��дtick����
	virtual void Tick(const FGeometry& AllottedGeometry, const double InCurrentTime, const float InDeltaTime)
		override;

private:

	//�󶨵�����MenuItem�ķ���
	void MenuItemOnClicked(EMenuItem::Type ItemType);
	//�޸�����
	void ChangeCulture(ECultrueTeam Culture);
	//�޸�����
	void ChangeVolume(const float MusicVolume, const float SoundVolume);
	//��ʼ�����еĿؼ�
	void InitializeMenuList();

	//ѡ����ʾ�Ľ���
	void ChooseWidget(EMenuType::Type WidgetType);

	//�޸Ĳ˵��Ĵ�С
	void ResetWidgetSize(float NewWidget, float NewHeight);

	//��ʼ���������
	void InitializedAnimation();

	//���Źرն���
	void PlayClose(EMenuType::Type NewMenu);

	//�˳���Ϸ
	void QuitGame();

	//������Ϸ
	void EnterGame();

private:

	//��ȡMenuStyle
	const struct FSlAiStyle* MenuStyle;

	//������ڵ��ֵ
	TSharedPtr<SBox> RootSizeBox;

	//�������
	TSharedPtr<STextBlock> TitleText;

	//�������洹ֱ�б�
	TSharedPtr<SVerticalBox> ContentBox;

	//����˵���
	TMap<EMenuType::Type, TSharedPtr<MenuGroup>> MenuMap;

	//��Ϸ����widget������
	TSharedPtr<SSlAiGameOptionWidget> GameOptionWidget;

	//����Ϸ�ؼ�ָ��
	TSharedPtr<SSlAiNewGameWidget> NewGameWidget;

	//ѡ��浵�ؼ�ָ��
	TSharedPtr<SSlAiChooseRecordWidget> ChooseRecordWidget;

	//����������
	FCurveSequence MenuAnimation;
	//���߿�����
	FCurveHandle MenuCurve;
	//���������µĳ���
	float CurrentHeight;
	//�Ƿ��Ѿ���ʾMenu���
	bool IsMenuShow;
	//�Ƿ���ס��ť
	bool ControlLocked;
	//���浱ǰ�Ķ���״̬
	EMenuAnim::Type AnimState;
	//���浱ǰ�Ĳ˵�
	EMenuType::Type CurrentMenu;
};
