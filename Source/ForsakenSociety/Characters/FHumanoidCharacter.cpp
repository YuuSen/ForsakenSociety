// Fill out your copyright notice in the Description page of Project Settings.


#include "FHumanoidCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
AFHumanoidCharacter::AFHumanoidCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Create camera boom
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(GetRootComponent());
	CameraBoom->TargetArmLength = 600.f; 
	CameraBoom->bUsePawnControlRotation = true;

	// Create FollowCamera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false;

	//Set our turn rate for input
	fBaseTurnRate = 65.f;
	fBaseLookupRate = 65.f;

	bUseControllerRotationYaw = false;
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...
	GetCharacterMovement()->RotationRate = FRotator(0.f, 540.f, 0.f); // ...at this rotation rate
	GetCharacterMovement()->JumpZVelocity = 600.f;
	GetCharacterMovement()->AirControl = .2f;

	fMaxZoom = 600.0f;
	fMinZoom = 200.0f;
	
	fRunningSpeed = 400.0f;
	fSprintingSpeed = 1000.0f;

	bSprintKeyDown = false;	
	
	fCrouchingSpeed = 300.0f;

	bCrouchKeyDown = false;
}

// Called when the game starts or when spawned
void AFHumanoidCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFHumanoidCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	ManageCharacterSpeed();
}

// Called to bind functionality to input
void AFHumanoidCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AFHumanoidCharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released,this, &ACharacter::StopJumping);
	
	PlayerInputComponent->BindAction("Sprint", IE_Pressed, this, &AFHumanoidCharacter::SprintKeyDown);
	PlayerInputComponent->BindAction("Sprint", IE_Released, this, &AFHumanoidCharacter::SprintKeyUp);

	PlayerInputComponent->BindAction("Crouch", IE_Pressed, this, &AFHumanoidCharacter::CrouchKeyDown);
	PlayerInputComponent->BindAction("Crouch", IE_Released, this, &AFHumanoidCharacter::CrouchKeyUp);

	PlayerInputComponent->BindAxis("MoveForward", this, &AFHumanoidCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AFHumanoidCharacter::MoveRight);

	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);

	PlayerInputComponent->BindAxis("TurnRate", this, &AFHumanoidCharacter::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUpRate", this, &AFHumanoidCharacter::LookUpRate);

	PlayerInputComponent->BindAxis("ScrollCamera", this, &AFHumanoidCharacter::ScrollInOut);
}

void AFHumanoidCharacter::MoveForward(float fValue)
{
	if ((Controller != nullptr) && (fValue != 0.0f))
	{
		// Find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0.f, Rotation.Yaw, 0.f);
	
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, fValue);
	}
}

void AFHumanoidCharacter::MoveRight(float fValue)
{
	if ((Controller != nullptr) && (fValue != 0.0f))
	{
		// Find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0.f, Rotation.Yaw, 0.f);

		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		AddMovementInput(Direction, fValue);
	}
}

void AFHumanoidCharacter::TurnAtRate(float fRate)
{
	AddControllerYawInput(fRate * fBaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void AFHumanoidCharacter::LookUpRate(float fRate)
{
	AddControllerPitchInput(fRate * fBaseLookupRate * GetWorld()->GetDeltaSeconds());
}

void AFHumanoidCharacter::ScrollInOut(float fValue)
{
	if (fValue != 0.0f)
	{
		float CurrentArmLenght = CameraBoom->TargetArmLength + fValue;

		if (CurrentArmLenght < fMaxZoom && CurrentArmLenght > fMinZoom)
		{
			CameraBoom->TargetArmLength += fValue;
		}
	}
}

void AFHumanoidCharacter::ManageCharacterSpeed()
{
	float currentSpeed = fRunningSpeed;

	if (bSprintKeyDown)
	{
		currentSpeed = fSprintingSpeed;	
	}
	else if (bCrouchKeyDown)
	{
		currentSpeed = fCrouchingSpeed;
	}
	
	GetCharacterMovement()->MaxWalkSpeed = currentSpeed;
}

void AFHumanoidCharacter::Jump()
{
	if (bCrouchKeyDown)
	{
		return;
	}

	Super::Jump();
}

void AFHumanoidCharacter::SprintKeyDown()
{
	bSprintKeyDown = true;
}

void AFHumanoidCharacter::SprintKeyUp()
{
	bSprintKeyDown = false;
}

void AFHumanoidCharacter::CrouchKeyDown()
{
	bCrouchKeyDown = true;
}

void AFHumanoidCharacter::CrouchKeyUp()
{
	bCrouchKeyDown = false;
}

