// Fill out your copyright notice in the Description page of Project Settings.


#include "ICD_GameMode_Race.h"
#include <ICD_GameState.h>
#include "Kismet/GameplayStatics.h"
#include <ICD_HUD.h>

AICD_GameMode_Race::AICD_GameMode_Race()
{
    GameStateClass = AICD_GameState::StaticClass();
    HUDClass = AICD_HUD::StaticClass();
}

void AICD_GameMode_Race::BeginPlay()
{
    Super::BeginPlay();
    StartCountdown();
}

void AICD_GameMode_Race::StartCountdown()
{
    if (AICD_GameState* GS = GetGameState<AICD_GameState>())
    {
        GS->CountdownTime = 3.0f;
        GS->bRaceInProgress = false;
        GetWorldTimerManager().SetTimer(CountdownHandle, this, &AICD_GameMode_Race::CountdownTick, 1.0f, true);
    }

    // Disable movement until race starts
    for (FConstPlayerControllerIterator It = GetWorld()->GetPlayerControllerIterator(); It; ++It)
        It->Get()->SetIgnoreMoveInput(true);
}

void AICD_GameMode_Race::CountdownTick()
{
    if (AICD_GameState* GS = GetGameState<AICD_GameState>())
    {
        GS->CountdownTime--;

        if (GS->CountdownTime <= -1.f) //-1 is to allow for the "GO!" message
        {
            GetWorldTimerManager().ClearTimer(CountdownHandle);
            StartRace();
        }
    }
}

void AICD_GameMode_Race::StartRace()
{
    if (AICD_GameState* GS = GetGameState<AICD_GameState>())
    {
        GS->RaceStartTime = GetWorld()->GetTimeSeconds();
        GS->bRaceInProgress = true;
    }

    // Open gates
    /*for (AGateActor* Gate : Gates)
        if (Gate) Gate->Open();*/

    // Enable movement
    for (FConstPlayerControllerIterator It = GetWorld()->GetPlayerControllerIterator(); It; ++It)
        It->Get()->SetIgnoreMoveInput(false);
}

void AICD_GameMode_Race::FinishRace(AController* Player)
{
    if (AICD_GameState* GS = GetGameState<AICD_GameState>())
        GS->bRaceInProgress = false;

    GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, TEXT("Race Finished!"));
}