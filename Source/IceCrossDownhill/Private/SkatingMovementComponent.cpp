// Fill out your copyright notice in the Description page of Project Settings.


#include "SkatingMovementComponent.h"

USkatingMovementComponent::USkatingMovementComponent()
{
    MaxDownhillSpeed = 2000.f;
    AccelFromStop = 500.f;
    AccelWhileMoving = 1500.f;
    MaxSlopeForFullPullDeg = 45.f;
}

void USkatingMovementComponent::PhysWalking(float DeltaTime, int32 Iterations)
{
    // Safety
    if (!CharacterOwner || !UpdatedComponent)
    {
        Super::PhysWalking(DeltaTime, Iterations);
        return;
    }

    // Apply slope acceleration only if we are standing on a floor
    if (CurrentFloor.bBlockingHit)
    {
        const FVector FloorNormal = CurrentFloor.HitResult.Normal.GetSafeNormal();
        const FVector Gravity = FVector(0.f, 0.f, -1.f);

        FVector Downhill = FVector::VectorPlaneProject(Gravity, FloorNormal).GetSafeNormal();
        float SlopeDot = FMath::Clamp(FVector::DotProduct(FloorNormal, FVector::UpVector), -1.f, 1.f);
        float SlopeAngleDeg = FMath::RadiansToDegrees(FMath::Acos(SlopeDot));

        const float MinSlopeToAffect = 0.5f;
        if (SlopeAngleDeg > MinSlopeToAffect)
        {
            float CurrentDownhillSpeed = FVector::DotProduct(Velocity, Downhill);

            // Appliquer le freinage si on va vers le haut
            if (CurrentDownhillSpeed < 0.f)
            {
                float UphillDrag = 200.f;
                float SpeedLoss = UphillDrag * DeltaTime;
                float NewSpeed = CurrentDownhillSpeed + SpeedLoss;
                // Ne pas bloquer à zéro, pour permettre à l'accélération de pente de prendre le relais
                Velocity += Downhill * (NewSpeed - CurrentDownhillSpeed);
                CurrentDownhillSpeed = NewSpeed;
            }

            // Toujours appliquer l'accélération de la pente
            float Accel = (CurrentDownhillSpeed > 0.f) ? AccelWhileMoving : AccelFromStop;
            float SlopeScale = FMath::Clamp(SlopeAngleDeg / MaxSlopeForFullPullDeg, 0.f, 1.f);
            Accel *= SlopeScale;

            float SpeedGain = Accel * DeltaTime;
            float TargetSpeed = FMath::Min(CurrentDownhillSpeed + SpeedGain, MaxDownhillSpeed);
            float SpeedIncrease = TargetSpeed - CurrentDownhillSpeed;

            Velocity += Downhill * SpeedIncrease;

            // Clamp la vitesse totale
            const float MaxOverallSpeed = MaxDownhillSpeed * 2.0f;
            Velocity = Velocity.GetClampedToMaxSize(MaxOverallSpeed);
        }
    }

    // Now run the normal walking physics so all other movement logic still runs
    Super::PhysWalking(DeltaTime, Iterations);
}