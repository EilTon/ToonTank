// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BasePawn.generated.h"

UCLASS()
class TOONTANKS_API ABasePawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABasePawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Base Pawn", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent *turretMesh;


private:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Base Pawn", meta = (AllowPrivateAccess = "true"))
	class UCapsuleComponent *capsuleComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Base Pawn", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent *baseMesh;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Base Pawn", meta = (AllowPrivateAccess = "true"))
	USceneComponent *projectileSpawnPoint;
	

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;


};
