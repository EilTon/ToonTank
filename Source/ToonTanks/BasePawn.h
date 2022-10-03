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

	void HandleDestruction();

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Base Pawn", meta = (AllowPrivateAccess = "true"))
	class UCapsuleComponent *capsuleComponent;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Base Pawn", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent *turretMesh;

	void RotateTurret(FVector LookAtTarget);

	void Fire();

private:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Base Pawn", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent *baseMesh;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Base Pawn", meta = (AllowPrivateAccess = "true"))
	USceneComponent *projectileSpawnPoint;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Base Pawn", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<class AProjectile> projectileClass;

	UPROPERTY(EditAnywhere)
	class UParticleSystem *deathParticle;

	UPROPERTY(EditAnywhere)
	class USoundBase *deathSound;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
