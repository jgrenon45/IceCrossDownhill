// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "ICD_GameState.generated.h"

/**
 * 
 */
UCLASS()
class ICECROSSDOWNHILL_API AICD_GameState : public AGameStateBase
{
	GENERATED_BODY()
	
public:
    AICD_GameState();

    // Remaining countdown seconds
    UPROPERTY(BlueprintReadOnly)
    float CountdownTime;

    // Time when race started (server time)
    UPROPERTY(BlueprintReadOnly)
    float RaceStartTime;

    UPROPERTY(BlueprintReadOnly)
    bool bRaceInProgress;

    UFUNCTION(BlueprintCallable)
    float GetRaceElapsedTime() const;
};
