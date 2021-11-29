// Fill out your copyright notice in the Description page of Project Settings.

// Replicated specifier enables the copy of an Actor on the server to replicate
// the value of a variable to all connected clients any time it changes

// ReplicatedUsing does the same thing, but enables us to set a RepNotify function
// that will be triggered when a client successfully receives the replicated data.

// GetLifetimeReplicatedProps function is responsible for replicating any properties we designate
// with the Replicated specifier, and enables us to configure how a property will replicate

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "DamageableActor.generated.h"

UCLASS()
class FORSAKENSOCIETY_API ADamageableActor : public ACharacter
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADamageableActor();

	/** Property replication */
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/** RepNotify for changes made to current health.*/
	UFUNCTION()
    void OnRep_CurrentHealth();	
	
	/** Response to health being updated. Called on the server immediately after modification, and on clients in response to a RepNotify*/
	void OnHealthUpdate();

public:

	UFUNCTION(BlueprintPure, Category="Health")
	FORCEINLINE float GetMaxHealth() const { return fMaxHealth; } 

	UFUNCTION(BlueprintPure, Category="Health")
    FORCEINLINE float GetCurrentHealth() const { return fCurrentHealth; }

	/** Setter for Current Health. Clamps the value between 0 and MaxHealth and calls OnHealthUpdate. Should only be called on the server.*/
	UFUNCTION(BlueprintCallable, Category="Health")
    void SetCurrentHealth(float healthValue);

	/** Event for taking damage. Overridden from APawn.*/
	UFUNCTION(BlueprintCallable, Category = "Health")
    float TakeDamage( float DamageTaken, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser ) override;
	
protected:
	
	UPROPERTY(EditDefaultsOnly, Category = "Health")
	float fMaxHealth;	

	/** The player's current health. When reduced to 0, they are considered dead.*/
	UPROPERTY(ReplicatedUsing=OnRep_CurrentHealth)
	float fCurrentHealth;
};
