// Fill out your copyright notice in the Description page of Project Settings.


#include "TimerWidget.h"
#include "Components/TextBlock.h"

void UTimerWidget::SetCountdownTime(float Time)
{
	if (CountDownTime)
	{
		// When the countdown reaches zero, display "GO!" and hide the countdown
		if (Time <= 0.f) 
		{
			CountDownTime->SetText(FText::FromString(TEXT("GO !")));
			GetWorld()->GetTimerManager().SetTimer(TempTimerHandle, [this]()
				{
					ToggleCountdownVisibility(false);
				}, 0.3f, false);
		}
		else
			CountDownTime->SetText(FText::AsNumber(Time, &FNumberFormattingOptions::DefaultNoGrouping()));
	}
}

void UTimerWidget::SetRaceTime(float Time)
{
	if (RaceTime)
	{
		RaceTime->SetText(FormatTime(Time));
	}
}

void UTimerWidget::ToggleRaceTimeVisibility(bool bVisible)
{
	if (RaceTime)
	{
		RaceTime->SetVisibility(bVisible ? ESlateVisibility::Visible : ESlateVisibility::Hidden);
	}
}

void UTimerWidget::ToggleCountdownVisibility(bool bVisible)
{
	if (CountDownTime)
	{
		CountDownTime->SetVisibility(bVisible ? ESlateVisibility::Visible : ESlateVisibility::Hidden);
		if (!bVisible)
		{
			GetWorld()->GetTimerManager().ClearTimer(TempTimerHandle);
		}
	}
}

/// <summary>
/// Formats the time in MM:SS:MS format.
/// </summary>
/// <param name="Time"></param>
/// <returns></returns>
FText UTimerWidget::FormatTime(float Time)
{
	int32 Minutes = FMath::FloorToInt(Time / 60.f);
	int32 Seconds = FMath::FloorToInt(FMath::Fmod(Time, 60.f));
	int32 Milliiseconds = FMath::FloorToInt(FMath::Fmod(Time * 100.f, 100.f));
	return FText::FromString(FString::Printf(TEXT("%02d:%02d:%02d"), Minutes, Seconds, Milliiseconds));
}
