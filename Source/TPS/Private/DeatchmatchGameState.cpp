// Fill out your copyright notice in the Description page of Project Settings.


#include "DeatchmatchGameState.h"

void ADeatchmatchGameState::UpdateMatchTime(float DeltaTime)
{
    MatchDuration -= DeltaTime;
    if (MatchDuration <= 0)
    {
        
        MatchDuration = 0;
       
    }
}

void ADeatchmatchGameState::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);

    if (GetNetMode() == NM_ListenServer || GetNetMode() == NM_DedicatedServer )
    {
        UpdateMatchTime(DeltaSeconds);
    }
}

void ADeatchmatchGameState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);

    DOREPLIFETIME_CONDITION(ADeatchmatchGameState, MatchDuration, COND_None);
}



