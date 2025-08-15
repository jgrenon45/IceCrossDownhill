// Fill out your copyright notice in the Description page of Project Settings.


#include "ICD_GameState.h"

AICD_GameState::AICD_GameState()
{
    CountdownTime = 3.0f;
    RaceStartTime = 0.0f;
    bRaceInProgress = false;
}

float AICD_GameState::GetRaceElapsedTime() const
{
    return bRaceInProgress ? GetWorld()->GetTimeSeconds() - RaceStartTime : 0.0f;
}