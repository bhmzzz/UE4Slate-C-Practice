// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
template<class T>
class SLATEPRACTICE_API SlAiSingleton
{
public:
	static TSharedPtr<T> Get();

private:
	static void Initialize();

	static TSharedRef<T> Create();

private:
	static TSharedPtr<T> TInstance;
};


template<class T>
TSharedPtr<T> SlAiSingleton<T>::TInstance = NULL;

template<class T>
inline TSharedPtr<T> SlAiSingleton<T>::Get()
{
	TSharedRef<T> TRef = MakeShareable(new T());
	return TRef;
}

template<class T>
inline void SlAiSingleton<T>::Initialize()
{
	if (!TInstance.IsValid())
		TInstance = Create();
}

template<class T>
inline TSharedRef<T> SlAiSingleton<T>::Create()
{
	Initialize();
	return TInstance;
}
