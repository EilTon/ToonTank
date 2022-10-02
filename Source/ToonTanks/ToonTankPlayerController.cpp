// Fill out your copyright notice in the Description page of Project Settings.


#include "ToonTankPlayerController.h"
#include "GameFramework/Pawn.h"

void AToonTankPlayerController::SetPlayerEnableState(bool PlayerEnabled)
{
	if (PlayerEnabled)
	{
		GetPawn()->EnableInput(this);

	}
	else
	{
		GetPawn()->DisableInput(this);
	}
}
