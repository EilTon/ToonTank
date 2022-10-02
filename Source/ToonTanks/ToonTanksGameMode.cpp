// Fill out your copyright notice in the Description page of Project Settings.

#include "ToonTanksGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "Tank.h"
#include "Tower.h"
#include "ToonTankPlayerController.h"
#include "TimerManager.h"

void AToonTanksGameMode::BeginPlay()
{
	Super::BeginPlay();
	HandleGameStart();

}

void AToonTanksGameMode::HandleGameStart()
{
	NumberOfTowersRemain = GetAllTowers();
	Tank = (ATank*)UGameplayStatics::GetPlayerPawn(this, 0);
	ToonTankPlayerController = (AToonTankPlayerController*)UGameplayStatics::GetPlayerController(this, 0);
	StartGame();
	if (ToonTankPlayerController)
	{
		ToonTankPlayerController->SetPlayerEnableState(false);
		FTimerHandle PlayerEnableTimerHandle;
		FTimerDelegate PlayerEnableTimerDelegate = FTimerDelegate::CreateUObject(ToonTankPlayerController, &AToonTankPlayerController::SetPlayerEnableState, true);
		GetWorldTimerManager().SetTimer(PlayerEnableTimerHandle, PlayerEnableTimerDelegate, StartDelay, false);
	}
}

int32 AToonTanksGameMode::GetAllTowers()
{
	TArray<AActor*> Towers;
	 UGameplayStatics::GetAllActorsOfClass(this, ATower::StaticClass(), Towers);
	 return Towers.Num();
}

void AToonTanksGameMode::ActorDied(AActor* DeadActor)
{
	if (DeadActor == Tank)
	{
		Tank->HandleDestruction();
		if (ToonTankPlayerController)
		{
			ToonTankPlayerController->SetPlayerEnableState(false);
		}
		GameOver(false);
	}

	else
	{
		Tower = (ATower*)DeadActor;
		if (Tower != nullptr)
		{
			Tower->HandleDestruction();
			--NumberOfTowersRemain;
			if (NumberOfTowersRemain <= 0)
			{
				GameOver(true);
			}
		}
	}
}
