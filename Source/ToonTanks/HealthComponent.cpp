// Fill out your copyright notice in the Description page of Project Settings.

#include "HealthComponent.h"
#include "Kismet/GameplayStatics.h"
#include "ToonTanksGameMode.h"
// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();
	currentHealth = maxHealth;
	GetOwner()->OnTakeAnyDamage.AddDynamic(this, &UHealthComponent::DamageTaken);
	ToonTankGameMode = (AToonTanksGameMode *)UGameplayStatics::GetGameMode(this);
	// ...
}

// Called every frame
void UHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UHealthComponent::DamageTaken(AActor *DamageActor, float Damage, const UDamageType *DamageType, AController *Instigator, AActor *DamageCauser)
{
	if (Damage > 0)
	{
		currentHealth -= Damage;
	}
	if (currentHealth < 0)
	{
		if (ToonTankGameMode != nullptr)
		{
			ToonTankGameMode->ActorDied(DamageActor);
		}
	}
}
