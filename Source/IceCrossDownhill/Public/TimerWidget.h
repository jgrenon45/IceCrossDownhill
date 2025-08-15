// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"
#include "TimerWidget.generated.h"

class UTextBlock;

UCLASS()
class ICECROSSDOWNHILL_API UTimerWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
    void SetCountdownTime(float Time);

    void SetRaceTime(float Time);

	void ToggleRaceTimeVisibility(bool bVisible);

	void ToggleCountdownVisibility(bool bVisible);

protected:
    UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
    TObjectPtr<UTextBlock> RaceTime;

    UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
    TObjectPtr<UTextBlock> CountDownTime;

private:
    FTimerHandle TempTimerHandle;

	FText FormatTime(float Time);
};
