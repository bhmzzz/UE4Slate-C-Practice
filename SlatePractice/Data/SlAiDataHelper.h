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

	//修改中英文
	void ChnageLocalizationCulture(ECultrueTeam Culture);
	//修改菜单音量
	void ResetMenuVolume(float MusicVal, float SoundVal);
public:
	//这个值会传递给下一张UI，比如从主页面UI切换之后还是需要知道当前设置的语言类别
	ECultrueTeam CurrentCulture;
	//保存音量
	float MusicVolume;
	float SoundVolume;

	//存档数据
	TArray<FString> RecordDataList;

	//存档名
	FString RecordName;

private:
	//创建单例
	static TSharedRef<SlAiDataHelper> Create();

	//根据enum类型获取字符串
	template<typename TEnum>
	FString GetEnumValueAsString(const FString& name, TEnum Value);

	//根据字符串获取enum值
	template<typename TEnum>
	TEnum GetEnumValueFromString(const FString& Name, FString Value);

	//初始化存档数据
	void InitRecordData();
	//初始化Menu声音数据
	void InitializedMenuAudio();

private:
	static TSharedPtr<SlAiDataHelper> DataInstance;

	//保存Menu的声音
	TMap<FString, TArray<USoundCue*> > MenuAudioResource;
	//获取MenuStyle，里面存放的声音文件
	const struct FSlAiStyle* MenuStyle;
};
