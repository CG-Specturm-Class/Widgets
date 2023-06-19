// Copyright Epic Games, Inc. All Rights Reserved.

#include "EscapeRoomGameMode.h"
#include "EscapeRoomCharacter.h"
#include "UObject/ConstructorHelpers.h"

AEscapeRoomGameMode::AEscapeRoomGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
