// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "FHumanoidCharacter.generated.h"

/*
 * TODO Create a parent class that handle Health and common stat with NPC
 * This class is the base class for PlayableHumanoidCharacter
 */

UCLASS()
class FORSAKENSOCIETY_API AFHumanoidCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AFHumanoidCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/* CAMERA SECTION */
	UPROPERTY(VisibleAnywhere, Category= "Camera")
	class USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, Category = "Camera")
	class UCameraComponent* FollowCamera;

	UPROPERTY(EditAnywhere, Category = "Camera")
	float fBaseTurnRate;

	UPROPERTY(EditAnywhere, Category = "Camera")
	float fBaseLookupRate;

	UPROPERTY(EditAnywhere, Category = "CameraZoom")
	float fMaxZoom;

	UPROPERTY(EditAnywhere, Category = "CameraZoom")
	float fMinZoom;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Running")
	float fRunningSpeed;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Running")
	float fSprintingSpeed;

	bool bSprintKeyDown;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Crouching")
	float fCrouchingSpeed;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Crouching")
	bool bCrouchKeyDown;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	/* Called for forward/backward input */
	void MoveForward(float fValue);

	/* Called for side to side function */
	void MoveRight(float fValue);

	/* Called via input to turn at a given rate
	* @param Rate This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	*/
	void TurnAtRate(float fRate);

	/* Called via input to look up/down at a given rate
	* @param Rate This is a normalized rate, i.e. 1.0 means 100% of desired look up/down rate
	*/
	void LookUpRate(float fRate);

	void ScrollInOut(float fValue);
	
	void ManageCharacterSpeed();

	virtual void Jump() override;
	
	/** Pressed down to enable sprinting */
	void SprintKeyDown();

	/** Released to stop sprinting*/
	void SprintKeyUp();

	void CrouchKeyDown();

	void CrouchKeyUp();
};
