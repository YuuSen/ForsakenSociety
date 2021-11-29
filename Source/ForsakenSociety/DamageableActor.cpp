// Fill out your copyright notice in the Description page of Project Settings.


#include "DamageableActor.h"
#include "Net/UnrealNetwork.h"
#include "Engine/Engine.h"

#define ISDEDICATED (GEngine->GetNetMode(GetWorld()) == NM_DedicatedServer)
#define ISLISTEN (GEngine->GetNetMode(GetWorld()) == NM_ListenServer)
#define ISCLIENT (GEngine->GetNetMode(GetWorld()) == NM_Client)

// Sets default values
ADamageableActor::ADamageableActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	fMaxHealth = 100.0f;
	fCurrentHealth = fMaxHealth;
}

void ADamageableActor::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	//Replication section
	DOREPLIFETIME(ADamageableActor, fCurrentHealth);
}

void ADamageableActor::BeginPlay()
{
	Super::BeginPlay();
}

void ADamageableActor::OnRep_CurrentHealth()
{
	OnHealthUpdate();
}

/*
 * This method will only be executed on the server by checking the authority role
 */
void ADamageableActor::SetCurrentHealth(float healthValue)
{
	if (GetLocalRole() == ROLE_Authority)
	{
		fCurrentHealth = FMath::Clamp(healthValue, 0.f, fMaxHealth);
		OnHealthUpdate();
	}
}

float ADamageableActor::TakeDamage(float DamageTaken, FDamageEvent const& DamageEvent, AController* EventInstigator,
	AActor* DamageCauser)
{
	float DamageApplied = fCurrentHealth - DamageTaken;
	SetCurrentHealth(DamageApplied);
	return DamageApplied;
}

void ADamageableActor::OnHealthUpdate()
{
	//Client-specific functionality
	if (IsLocallyControlled())
	{
		if (fCurrentHealth <= 0)
		{
			UE_LOG(LogTemp, Warning, TEXT("%s has been killed."), *GetFName().ToString());
		}
	}

	//Server-specific functionality
	if (GetLocalRole() == ROLE_Authority)
	{
		
	}

	//Functions that occur on all machines. 
	/*  
	Any special functionality that should occur as a result of damage or death should be placed here. 
	*/
}


