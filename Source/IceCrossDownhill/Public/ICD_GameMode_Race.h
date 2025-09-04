// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Gates.h"
#include "ICD_GameMode_Race.generated.h"

/**
 * 
 */
UCLASS()
class ICECROSSDOWNHILL_API AICD_GameMode_Race : public AGameModeBase
{
	GENERATED_BODY()
	
public:
    AICD_GameMode_Race();

    virtual void BeginPlay() override;

    void StartCountdown();

    void CountdownTick();

    void StartRace();

    void FinishRace();

    void FinishLap();

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Race")
	int NumberOfLaps = 3; // Default value, can be set per level in Editor

private:
    FTimerHandle CountdownHandle;
};
