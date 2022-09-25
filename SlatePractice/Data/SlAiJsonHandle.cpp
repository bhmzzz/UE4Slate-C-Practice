// Fill out your copyright notice in the Description page of Project Settings.


#include "SlAiJsonHandle.h"
#include "SlatePractice/Common/SlAiHelper.h"

SlAiJsonHandle::SlAiJsonHandle()
{
	RecordDataFileName = FString("RecordData.json");

	RelativePath = FString("Res/ConfigData");
}

void SlAiJsonHandle::RecordDataHsonRead(FString& Culture, float& MusicVolume, float& SoundVolume, TArray<FString>& recordDataList)
{
	FString JsonValue;
	LoadStringFromFile(RecordDataFileName, RelativePath, JsonValue);

	TArray<TSharedPtr<FJsonValue>> JsonParsed;
	TSharedRef<TJsonReader<TCHAR>> JsonReader = TJsonReaderFactory<TCHAR>::Create(JsonValue);
	if (FJsonSerializer::Deserialize(JsonReader, JsonParsed))
	{
		//��ȡ����
		Culture = JsonParsed[0]->AsObject()->GetStringField(FString("Culture"));
		MusicVolume = JsonParsed[1]->AsObject()->GetNumberField(FString("MusicVolume"));
		SoundVolume = JsonParsed[2]->AsObject()->GetNumberField(FString("SoundVolume"));
		//��ȡ�浵����
		TArray<TSharedPtr<FJsonValue>> RecordDataArray = JsonParsed[3]->AsObject()->GetArrayField(FString("RecordData"));
		for (int i = 0; i < RecordDataArray.Num(); ++i)
		{
			FString RecordDataName = RecordDataArray[i]->AsObject()->GetStringField(FString::FromInt(i));
			recordDataList.Add(RecordDataName);
		}
	}
	else
	{
		SlAiHelperNS::Debug(FString("Deserialize Failed"));
	}
}

void SlAiJsonHandle::UpdateRecordData(FString Culture, float MusicVolume, float SoundVolume, TArray<FString>* RecordDataList)
{
	TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject);

	TArray<TSharedPtr<FJsonValue> > BaseDataArray;

	TSharedPtr<FJsonObject> CultureObject = MakeShareable(new FJsonObject);
	CultureObject->SetStringField("Culture", Culture);
	TSharedPtr<FJsonValueObject> CultureValue = MakeShareable(new FJsonValueObject(CultureObject));

	TSharedPtr<FJsonObject> MusicVolumeObject = MakeShareable(new FJsonObject);
	MusicVolumeObject->SetNumberField("MusicVolume", MusicVolume);
	TSharedPtr<FJsonValueObject> MusicVolumeValue = MakeShareable(new FJsonValueObject(MusicVolumeObject));
	
	TSharedPtr<FJsonObject> SoundVolumeObject = MakeShareable(new FJsonObject);
	SoundVolumeObject->SetNumberField("SoundVolume", SoundVolume);
	TSharedPtr<FJsonValueObject> SoundVolumeValue = MakeShareable(new FJsonValueObject(SoundVolumeObject));
	
	TArray<TSharedPtr<FJsonValue> > RecordDataArray;

	for (int i = 0; i < RecordDataList->Num(); ++i)
	{
		TSharedPtr<FJsonObject> RecordItem = MakeShareable(new FJsonObject);
		RecordItem->SetStringField(FString::FromInt(i), (*RecordDataList)[i]);
		TSharedPtr<FJsonValueObject> RecordDataValue = MakeShareable(new FJsonValueObject(RecordItem));
		RecordDataArray.Add(RecordDataValue);
	}
	TSharedPtr<FJsonObject> RecordDataObject = MakeShareable(new FJsonObject);
	RecordDataObject->SetArrayField("RecordData", RecordDataArray);
	TSharedPtr<FJsonValueObject> RecordDataValue = MakeShareable(new FJsonValueObject(RecordDataObject));

	BaseDataArray.Add(CultureValue);
	BaseDataArray.Add(MusicVolumeValue);
	BaseDataArray.Add(SoundVolumeValue);
	BaseDataArray.Add(RecordDataValue);

	JsonObject->SetArrayField("T", BaseDataArray);

	FString JsonStr;
	GetFStringInJsonData(JsonObject, JsonStr);

	//SlAiHelperNS::Debug(FString("Origin Str : " + JsonStr), 60.f);

	//ȥ��������ַ�
	JsonStr.RemoveAt(0, 8);
	JsonStr.RemoveFromEnd(FString("}"));

	//SlAiHelperNS::Debug(FString("Final Str : " + JsonStr), 60.f);

	//д���ļ�
	WriteFileWithJsonData(JsonStr, RelativePath, RecordDataFileName);
}

bool SlAiJsonHandle::LoadStringFromFile(const FString& FileName, const FString& RelaPath, FString& ResultString)
{
	if (!FileName.IsEmpty())
	{
		//��ȡ����·��
		FString AbsoPath = FPaths::GameSourceDir() + RelaPath + FileName;
		if (FPaths::FileExists(AbsoPath))
		{
			if (FFileHelper::LoadFileToString(ResultString, *AbsoPath))
			{
				return true;
			}
			else
			{
				//���ز��ɹ�
				SlAiHelperNS::Debug(FString("Load Error") + AbsoPath);
			}
		}
		else
		{
			//����ļ�������
			SlAiHelperNS::Debug(FString("File Not Exist") + AbsoPath);
		}
	}
	return false;
}

bool SlAiJsonHandle::GetFStringInJsonData(const TSharedPtr<FJsonObject>& JsonObj, FString& JsonStr)
{
	if (JsonObj.IsValid() && JsonObj->Values.Num() > 0)//�жϻ�ȡ����Json�����ֵ����
	{
		TSharedRef<TJsonWriter<TCHAR> > JsonWriter = TJsonWriterFactory<TCHAR>::Create(&JsonStr);//��Json�����ֵд�뵽JsonStr�ַ���
		FJsonSerializer::Serialize(JsonObj.ToSharedRef(), JsonWriter);
		return true;
	}
	return false;
}

bool SlAiJsonHandle::WriteFileWithJsonData(const FString& JsonStr, const FString& RelaPath, const FString& FileName)
{
	if (!JsonStr.IsEmpty())//�ж�Ҫд���Json�ַ����Ƿ�Ϊ��
	{
		if (!FileName.IsEmpty())//�ж�Json�ļ����Ƿ�Ϊ��
		{
			//��ȡJson�ļ��ľ���·��
			FString AbsoPath = FPaths::GameSourceDir() + RelaPath + FileName;
			//����浵�ַ�������Json�ļ�
			if (FFileHelper::SaveStringToFile(JsonStr, *AbsoPath)) {
				return true;
			}
			else {
				SlAiHelperNS::Debug(FString("Save") + AbsoPath + FString("-->Failed"), 10.f);
			}
		}
	}
	return false;
}
