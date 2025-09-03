// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Gates.generated.h"

UCLASS()
class ICECROSSDOWNHILL_API AGates : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGates();

public:	
	
	UFUNCTION(BlueprintImplementableEvent)
	void Open();

};
