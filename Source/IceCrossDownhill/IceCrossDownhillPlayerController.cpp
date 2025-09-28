// Copyright Epic Games, Inc. All Rights Reserved.


#include "IceCrossDownhillPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "ICD_HUD.h"
#include "Engine/LocalPlayer.h"
#include "InputMappingContext.h"

void AIceCrossDownhillPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	// Add Input Mapping Contexts
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		for (UInputMappingContext* CurrentContext : DefaultMappingContexts)
		{
			Subsystem->AddMappingContext(CurrentContext, 0);
		}
	}
}

void AIceCrossDownhillPlayerController::OnLapCompleted(float LapTime)
{
	if (AICD_HUD* HUD = Cast<AICD_HUD>(GetHUD()))
	{
		HUD->UpdateLapTime(LapTime);
	}
}
