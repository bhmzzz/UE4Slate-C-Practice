// Fill out your copyright notice in the Description page of Project Settings.


#include "SlAiWidgetStyle.h"

FSlAiStyle::FSlAiStyle()
{
}

FSlAiStyle::~FSlAiStyle()
{
}

const FName FSlAiStyle::TypeName(TEXT("FSlAiStyle"));

const FSlAiStyle& FSlAiStyle::GetDefault()
{
	static FSlAiStyle Default;
	return Default;
}

void FSlAiStyle::GetResources(TArray<const FSlateBrush*>& OutBrushes) const
{
	// Add any brush resources here so that Slate can correctly atlas and reference them
}

