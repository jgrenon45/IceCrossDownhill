// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "ICD_PlayerState.generated.h"

/**
 * 
 */
UCLASS()
class ICECROSSDOWNHILL_API AICD_PlayerState : public APlayerState
{
	GENERATED_BODY()
	
public :

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Race")
	int CurrentLap = 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Race")
	TMap<int, float> Laps;
	
	UFUNCTION(NotBlueprintable)
	void UpdateLaps(float Time);
};
