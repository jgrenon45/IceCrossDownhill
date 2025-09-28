// Fill out your copyright notice in the Description page of Project Settings.


#include "ICD_PlayerState.h"


void AICD_PlayerState::UpdateLaps(float Time)
{
	Laps.Add(CurrentLap, Time);
	CurrentLap++;
}
