// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "SlAiTypes.h"
#include "SlatePractice/UI/SlAIStyleClass.h"
#include "SlatePractice/UI/SlAIWidgetStyle.h"
#include "CoreMinimal.h"


class USoundCue;
/**
 * 
 */
class SLATEPRACTICE_API SlAiDataHelper
{
public:
	SlAiDataHelper();

	static void Initialize();

	static TSharedPtr<SlAiDataHelper> Get();

	//�޸���Ӣ��
	void ChnageLocalizationCulture(ECultrueTeam Culture);
	//�޸Ĳ˵�����
	void ResetMenuVolume(float MusicVal, float SoundVal);
public:
	//���ֵ�ᴫ�ݸ���һ��UI���������ҳ��UI�л�֮������Ҫ֪����ǰ���õ��������
	ECultrueTeam CurrentCulture;
	//��������
	float MusicVolume;
	float SoundVolume;

	//�浵����
	TArray<FString> RecordDataList;

	//�浵��
	FString RecordName;

private:
	//��������
	static TSharedRef<SlAiDataHelper> Create();

	//����enum���ͻ�ȡ�ַ���
	template<typename TEnum>
	FString GetEnumValueAsString(const FString& name, TEnum Value);

	//�����ַ�����ȡenumֵ
	template<typename TEnum>
	TEnum GetEnumValueFromString(const FString& Name, FString Value);

	//��ʼ���浵����
	void InitRecordData();
	//��ʼ��Menu��������
	void InitializedMenuAudio();

private:
	static TSharedPtr<SlAiDataHelper> DataInstance;

	//����Menu������
	TMap<FString, TArray<USoundCue*> > MenuAudioResource;
	//��ȡMenuStyle�������ŵ������ļ�
	const struct FSlAiStyle* MenuStyle;
};
