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
	////��ʼ��Ϊ����
	//CurrentCulture = ECultrueTeam::ZH;
	////��ʼ������
	//MusicVolume = 0.5f;
	//SoundVolume = 0.5f;

	//��ʼ���浵����
	InitRecordData();
	//��ʼ����������
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
	//��ֵ
	CurrentCulture = Culture;

	//���´浵����
	SlAiSingleton<SlAiJsonHandle>::Get()->UpdateRecordData(GetEnumValueAsString<ECultrueTeam>(FString("ECultrueTeam"),
		CurrentCulture), MusicVolume, SoundVolume, &RecordDataList);
}

void SlAiDataHelper::ResetMenuVolume(float MusicVal, float SoundVal)
{
	if (MusicVal > 0)
	{
		MusicVolume = MusicVal;
		//ѭ�����ñ�����������
		for (TArray<USoundCue*>::TIterator It(MenuAudioResource.Find(FString("Music"))->CreateIterator()); It; ++It) 
		{
			//��������
			(*It)->VolumeMultiplier = MusicVolume;
		}
	}
	if (SoundVal > 0)
	{
		SoundVolume = SoundVal;
		//ѭ�����ñ���������Ч
		for (TArray<USoundCue*>::TIterator It(MenuAudioResource.Find(FString("Sound"))->CreateIterator()); It; ++It)
		{
			//ָ���ָ��
			(*It)->VolumeMultiplier = SoundVolume;
		}
	}

	//���´浵����
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

	//��ȡ����
	FString Culture;
	//��ȡ�浵����
	SlAiSingleton<SlAiJsonHandle>::Get()->RecordDataHsonRead(Culture, MusicVolume, SoundVolume, RecordDataList);
	
	//��ʼ������
	ChnageLocalizationCulture(GetEnumValueFromString<ECultrueTeam>(FString("ECultureTeam"), Culture));
	

	//���һ��
	SlAiHelperNS::Debug(Culture + FString("--") + FString::SanitizeFloat(MusicVolume) + FString("--") + FString::SanitizeFloat(SoundVolume),20.f);
	//ѭ����ȡRecordDataList
	for (TArray<FString>::TIterator It(RecordDataList); It; ++It)
	{
		SlAiHelperNS::Debug(*It, 20.f);
	}
}

void SlAiDataHelper::InitializedMenuAudio()
{
	//��ȡMenuStyle
	MenuStyle = &SlAiStyleClass::Get().GetWidgetStyle<FSlAiStyle>("BPSlAiMenuStyle");

	//�����Դ�ļ�����Դ�б�
	TArray<USoundCue*> MusicList;
	MusicList.Add(Cast<USoundCue>(MenuStyle->MenuBackgroundMusic.GetResourceObject()));
	TArray<USoundCue*> SoundList;
	SoundList.Add(Cast<USoundCue>(MenuStyle->StartGameSound.GetResourceObject()));
	SoundList.Add(Cast<USoundCue>(MenuStyle->ExitGameSound.GetResourceObject()));
	SoundList.Add(Cast<USoundCue>(MenuStyle->MenuItemChangeSound.GetResourceObject()));

	//�����Դ��Map
	MenuAudioResource.Add(FString("Music"), MusicList);
	MenuAudioResource.Add(FString("Sound"), SoundList);

	//����һ������
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







