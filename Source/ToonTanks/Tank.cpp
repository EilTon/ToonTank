// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

ATank::ATank()
{
    springArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
    cameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));

    springArmComponent->SetupAttachment(RootComponent);
    cameraComponent->SetupAttachment(springArmComponent);
}
