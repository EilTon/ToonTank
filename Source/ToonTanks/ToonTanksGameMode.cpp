// Fill out your copyright notice in the Description page of Project Settings.

#include "ToonTanksGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "Tank.h"
#include "Tower.h"

void AToonTanksGameMode::BeginPlay()
{
    Super::BeginPlay();
    Tank = (ATank *)UGameplayStatics::GetPlayerPawn(this, 0);
}

void AToonTanksGameMode::ActorDied(AActor *DeadActor)
{
    if (DeadActor == Tank)
    {
        Tank->HandleDestruction();
        if (Tank->GetPlayerController())
        {
            Tank->DisableInput(Tank->GetPlayerController());
            Tank->GetPlayerController()->bShowMouseCursor = false;
        }
    }

    else
    {
        Tower = (ATower *)DeadActor;
        UE_LOG(LogTemp, Warning, TEXT("BeforeNullPTr"));
        if (Tower != nullptr)
        {
            UE_LOG(LogTemp, Warning, TEXT("AfterNullPTr"));
            Tower->HandleDestruction();
        }
    }
}
