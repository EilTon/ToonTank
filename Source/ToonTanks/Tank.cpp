// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/GameplayStatics.h"
#include "DrawDebugHelpers.h"

ATank::ATank()
{
	springArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	cameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));

	springArmComponent->SetupAttachment(RootComponent);
	cameraComponent->SetupAttachment(springArmComponent);
}

void ATank::BeginPlay()
{
	Super::BeginPlay();
	playerController = (APlayerController*)GetController();
}

void ATank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (playerController != nullptr)
	{
		FHitResult hitResult;
		playerController->GetHitResultUnderCursor(ECollisionChannel::ECC_Visibility, false, hitResult);
		DrawDebugSphere(GetWorld(), hitResult.ImpactPoint, 100, 12, FColor::Red, false, -1);
		RotateTurret(hitResult.ImpactPoint);
	}
}

void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &ATank::Move);
	PlayerInputComponent->BindAxis(TEXT("Turn"), this, &ATank::Turn);
	PlayerInputComponent->BindAction(TEXT("Fire"), IE_Pressed, this, &ATank::Fire);
}

void ATank::Move(float Value)
{
	FVector deltaLocation = FVector::ZeroVector;
	deltaLocation.X = Value * speedMove * UGameplayStatics::GetWorldDeltaSeconds(this);
	AddActorLocalOffset(deltaLocation, true);
}

void ATank::Turn(float Value)
{
	FRotator deltaRotation = FRotator::ZeroRotator;
	deltaRotation.Yaw = Value * speedTurn * UGameplayStatics::GetWorldDeltaSeconds(this);
	AddActorLocalRotation(deltaRotation, true);
}

void ATank::HandleDestruction()
{
	Super::HandleDestruction();
	SetActorHiddenInGame(true);
	SetActorTickEnabled(false);

}
