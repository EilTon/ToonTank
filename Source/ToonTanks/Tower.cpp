// Fill out your copyright notice in the Description page of Project Settings.

#include "Tower.h"
#include "Tank.h"
#include "Kismet/GameplayStatics.h"

void ATower::BeginPlay()
{
    Super::BeginPlay();
    tank = (ATank *)UGameplayStatics::GetPlayerPawn(this, 0);
}

void ATower::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    UE_LOG(LogTemp,Display,TEXT("I GOT noty THE TANK"));
    if (tank)
    {
        UE_LOG(LogTemp,Display,TEXT("I GOT THE TANK"));
        float distance = FVector::Dist(GetActorLocation(), tank->GetActorLocation());
        if(distance<fireRange)
        {   
            UE_LOG(LogTemp,Display,TEXT("WHAT"));
            RotateTurret(tank->GetActorLocation());
        }
    }
}
