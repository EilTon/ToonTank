// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Tank.generated.h"

/**
 *
 */
UCLASS()
class TOONTANKS_API ATank : public ABasePawn
{
	GENERATED_BODY()
public:
	ATank();

	virtual void SetupPlayerInputComponent(class UInputComponent *PlayerInputComponent) override;

private:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	class UCameraComponent *cameraComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent *springArmComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement", meta = (AllowPrivateAccess = "true"))
	float speedMove = 200;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement", meta = (AllowPrivateAccess = "true"))
	float speedTurn = 100;

	void Move(float Value);
	void Turn(float Value);
};
