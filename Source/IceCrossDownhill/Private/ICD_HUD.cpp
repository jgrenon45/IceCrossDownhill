// Fill out your copyright notice in the Description page of Project Settings.


#include "ICD_HUD.h"
#include "TimerWidget.h"
#include "Blueprint/UserWidget.h"
#include "ICD_GameState.h"
#include <Kismet/GameplayStatics.h>

void AICD_HUD::BeginPlay()
{
    Super::BeginPlay();

    if (TimerWidgetClass)
    {
        TimerWidget = CreateWidget<UTimerWidget>(GetWorld(), TimerWidgetClass);
        if (TimerWidget)
        {
            TimerWidget->AddToViewport();
        }
    }
    CachedGameState = Cast<AICD_GameState>(UGameplayStatics::GetGameState(this));
}

void AICD_HUD::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);

    if (TimerWidget && CachedGameState)
    {
        float CurrentTime = CachedGameState->bRaceInProgress ? CachedGameState->GetRaceElapsedTime() : CachedGameState->CountdownTime;

        if (!FMath::IsNearlyEqual(CurrentTime, LastDisplayedTime))
        {
            if (CachedGameState->bRaceInProgress)
                UpdateRaceTime(CurrentTime);
            else
                UpdateCountdown(CurrentTime);

            LastDisplayedTime = CurrentTime;
        }
    }
}

void AICD_HUD::UpdateCountdown(float NewTime)
{
    if (TimerWidget)
        TimerWidget->SetCountdownTime(NewTime);
}

void AICD_HUD::UpdateRaceTime(float NewTime)
{
    if (TimerWidget)
        TimerWidget->SetRaceTime(NewTime);
}

void AICD_HUD::UpdateLapTime(float NewTime)
{
    if (TimerWidget)
        TimerWidget->SetLapTime(NewTime);
}