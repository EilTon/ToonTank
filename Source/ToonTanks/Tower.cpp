// Fill out your copyright notice in the Description page of Project Settings.

#include "Tower.h"
#include "Tank.h"
#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"

void ATower::BeginPlay()
{
	Super::BeginPlay();
	tank = (ATank*)UGameplayStatics::GetPlayerPawn(this, 0);
	GetWorldTimerManager().SetTimer(fireRateTimerHandle, this, &ATower::CheckFireCondition, fireRate, true);
}

void ATower::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (CheckFireRange())
	{
		RotateTurret(tank->GetActorLocation());
	}
}

void ATower::CheckFireCondition()
{
	if (CheckFireRange())
	{
		Fire();
	}
}

bool ATower::CheckFireRange()
{
	if (tank)
	{
		float distance = FVector::Dist(GetActorLocation(), tank->GetActorLocation());
		if (distance < fireRange)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

void ATower::HandleDestruction()
{
	Super::HandleDestruction();
	Destroy();
}
