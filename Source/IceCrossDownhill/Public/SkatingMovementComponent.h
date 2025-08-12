// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "SkatingMovementComponent.generated.h"

/**
 * 
 */
UCLASS()
class ICECROSSDOWNHILL_API USkatingMovementComponent : public UCharacterMovementComponent
{
	GENERATED_BODY()
	
public:
    USkatingMovementComponent();

    // Tunables (expose and tweak in the editor)
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Skating")
    float MaxDownhillSpeed = 2000.f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Skating")
    float AccelFromStop = 500.f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Skating")
    float AccelWhileMoving = 1500.f;

    // slope angle (deg) that produces "full" pull (e.g. 45°)
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Skating")
    float MaxSlopeForFullPullDeg = 45.f;

    virtual void PhysWalking(float DeltaTime, int32 Iterations) override;
};
