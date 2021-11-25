// Copyright Epic Games, Inc. All Rights Reserved.

#include "ForsakenSocietyGameMode.h"
#include "ForsakenSocietyCharacter.h"
#include "UObject/ConstructorHelpers.h"

AForsakenSocietyGameMode::AForsakenSocietyGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
