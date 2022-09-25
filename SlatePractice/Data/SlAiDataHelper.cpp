// Fill out your copyright notice in the Description page of Project Settings.


#include "SlAiDataHelper.h"
#include "Internationalization/Internationalization.h"
#include "SlAiJsonHandle.h"
#include "SlAiSingleton.h"
#include "SlatePractice/Common/SlAiHelper.h"
#include "Sound/SoundCue.h"

TSharedPtr<SlAiDataHelper> SlAiDataHelper::DataInstance = NULL;

SlAiDataHelper::SlAiDataHelper()
{
	////初始化为中文
	//CurrentCulture = ECultrueTeam::ZH;
	////初始化音量
	//MusicVolume = 0.5f;
	//SoundVolume = 0.5f;

	//初始化存档数据
	InitRecordData();
	//初始化音乐数据
	InitializedMenuAudio();
}

void SlAiDataHelper::Initialize()
{
	if (!DataInstance.IsValid())
	{
		DataInstance = Create();
	}
}

TSharedPtr<SlAiDataHelper> SlAiDataHelper::Get()
{
	Initialize();
	return DataInstance;
}

void SlAiDataHelper::ChnageLocalizationCulture(ECultrueTeam Culture)
{
	switch (Culture)
	{
	case ECultrueTeam::EN:
		FInternationalization::Get().SetCurrentCulture(TEXT("en"));
		break;
	case ECultrueTeam::ZH:
		FInternationalization::Get().SetCurrentCulture(TEXT("zh"));
		break;
	}
	//赋值
	CurrentCulture = Culture;

	//更新存档数据
	SlAiSingleton<SlAiJsonHandle>::Get()->UpdateRecordData(GetEnumValueAsString<ECultrueTeam>(FString("ECultrueTeam"),
		CurrentCulture), MusicVolume, SoundVolume, &RecordDataList);
}

void SlAiDataHelper::ResetMenuVolume(float MusicVal, float SoundVal)
{
	if (MusicVal > 0)
	{
		MusicVolume = MusicVal;
		//循环设置背景音乐音量
		for (TArray<USoundCue*>::TIterator It(MenuAudioResource.Find(FString("Music"))->CreateIterator()); It; ++It) 
		{
			//设置音量
			(*It)->VolumeMultiplier = MusicVolume;
		}
	}
	if (SoundVal > 0)
	{
		SoundVolume = SoundVal;
		//循环设置背景音乐音效
		for (TArray<USoundCue*>::TIterator It(MenuAudioResource.Find(FString("Sound"))->CreateIterator()); It; ++It)
		{
			//指针的指针
			(*It)->VolumeMultiplier = SoundVolume;
		}
	}

	//更新存档数据
	SlAiSingleton<SlAiJsonHandle>::Get()->UpdateRecordData(GetEnumValueAsString<ECultrueTeam>(FString("ECultrueTeam"),
		CurrentCulture), MusicVolume, SoundVolume, &RecordDataList);
}

TSharedRef<SlAiDataHelper> SlAiDataHelper::Create()
{
	TSharedRef<SlAiDataHelper> DataRef = MakeShareable(new SlAiDataHelper());
	return DataRef;
}

void SlAiDataHelper::InitRecordData()
{
	RecordName = FString("");

	//获取语言
	FString Culture;
	//读取存档数据
	SlAiSingleton<SlAiJsonHandle>::Get()->RecordDataHsonRead(Culture, MusicVolume, SoundVolume, RecordDataList);
	
	//初始化语言
	ChnageLocalizationCulture(GetEnumValueFromString<ECultrueTeam>(FString("ECultureTeam"), Culture));
	

	//输出一下
	SlAiHelperNS::Debug(Culture + FString("--") + FString::SanitizeFloat(MusicVolume) + FString("--") + FString::SanitizeFloat(SoundVolume),20.f);
	//循环读取RecordDataList
	for (TArray<FString>::TIterator It(RecordDataList); It; ++It)
	{
		SlAiHelperNS::Debug(*It, 20.f);
	}
}

void SlAiDataHelper::InitializedMenuAudio()
{
	//获取MenuStyle
	MenuStyle = &SlAiStyleClass::Get().GetWidgetStyle<FSlAiStyle>("BPSlAiMenuStyle");

	//添加资源文件到资源列表
	TArray<USoundCue*> MusicList;
	MusicList.Add(Cast<USoundCue>(MenuStyle->MenuBackgroundMusic.GetResourceObject()));
	TArray<USoundCue*> SoundList;
	SoundList.Add(Cast<USoundCue>(MenuStyle->StartGameSound.GetResourceObject()));
	SoundList.Add(Cast<USoundCue>(MenuStyle->ExitGameSound.GetResourceObject()));
	SoundList.Add(Cast<USoundCue>(MenuStyle->MenuItemChangeSound.GetResourceObject()));

	//添加资源到Map
	MenuAudioResource.Add(FString("Music"), MusicList);
	MenuAudioResource.Add(FString("Sound"), SoundList);

	//重置一下声音
	ResetMenuVolume(MusicVolume, SoundVolume);
}

template<typename TEnum>
inline FString SlAiDataHelper::GetEnumValueAsString(const FString& name, TEnum Value)
{
	const UEnum* EnumPtr = FindObject<UEnum>(ANY_PACKAGE, *name, true);
	if (!EnumPtr)
	{
		return FString("Invalid");
	}
	return EnumPtr->GetEnumName((int32)Value);
}

template<typename TEnum>
inline TEnum SlAiDataHelper::GetEnumValueFromString(const FString& Name, FString Value)
{
	const UEnum* EnumPtr = FindObject<UEnum>(ANY_PACKAGE, *Name, true);
	if (!EnumPtr)
	{
		return TEnum(0);
	}
	return (TEnum)EnumPtr->GetIndexByName(FName(*FString(Value)));
}







