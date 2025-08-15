// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "ICD_HUD.generated.h"

class UTimerWidget;
class AICD_GameState;

UCLASS()
class ICECROSSDOWNHILL_API AICD_HUD : public AHUD
{
	GENERATED_BODY()
	
public:
    virtual void BeginPlay() override;

    virtual void Tick(float DeltaSeconds) override;

    UPROPERTY(EditDefaultsOnly, Category = "UI")
    TSubclassOf<UUserWidget> TimerWidgetClass;

    UPROPERTY()
    TObjectPtr<UTimerWidget> TimerWidget;

    void UpdateCountdown(float NewTime);
    void UpdateRaceTime(float NewTime);

private:
    TObjectPtr<AICD_GameState> CachedGameState;

    float LastDisplayedTime = -1.f;

};
