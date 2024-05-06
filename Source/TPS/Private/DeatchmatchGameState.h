// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "Net/UnrealNetwork.h" 
#include "DeatchmatchGameState.generated.h"

/**
 * 
 */
UCLASS()
class ADeatchmatchGameState : public AGameStateBase
{
	GENERATED_BODY()
	
public:
    // Конструктор
    ADeatchmatchGameState()
    {
        PrimaryActorTick.bCanEverTick = true;
        SetActorTickInterval(1.0f);
        MatchDuration = 300; // Set default match duration as 5 minutes
    }

    // Match duratuion (seconds)
    UPROPERTY(ReplicatedUsing = OnRep_MatchDuration, EditAnywhere, BlueprintReadWrite, Category = "Gameplay")
    float MatchDuration;

    void UpdateMatchTime(float DeltaTime);

    UFUNCTION()
    void OnRep_MatchDuration()
    {
       
    }

    virtual void Tick(float DeltaSeconds) override;
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

};