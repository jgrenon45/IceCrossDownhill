// Fill out your copyright notice in the Description page of Project Settings.


#include "FinishLine.h"
#include <ICD_PlayerState.h>
#include "ICD_GameMode_Race.h"
#include "IceCrossDownhillPlayerController.h"

// Sets default values
AFinishLine::AFinishLine()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
    TriggerBox = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerBox"));
    RootComponent = TriggerBox;
    TriggerBox->OnComponentBeginOverlap.AddDynamic(this, &AFinishLine::OnOverlapBegin);

}

void AFinishLine::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
    UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    if (APawn* Pawn = Cast<APawn>(OtherActor))
    {
		AICD_PlayerState* PS = Cast<AICD_PlayerState>(Pawn->GetPlayerState());
        AIceCrossDownhillPlayerController* PC = Cast<AIceCrossDownhillPlayerController>(Pawn->GetController());
        if (AICD_GameMode_Race* GM = GetWorld()->GetAuthGameMode<AICD_GameMode_Race>())
        {
            GM->FinishLap(PS, PC);
            
            // Check if race is finished
            if (PS->CurrentLap > GM->NumberOfLaps)
            {
                GM->FinishRace();
                Destroy();
            }
        }
    }
}

