// Copyright Epic Games, Inc. All Rights Reserved.

#include "EscapeRoomGameMode.h"
#include "EscapeRoomCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h"
#include <Subsystems/PanelExtensionSubsystem.h>
#include "ObjectiveHUD.h"

AEscapeRoomGameMode::AEscapeRoomGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}


void AEscapeRoomGameMode::BeginPlay()
{
	Super::BeginPlay();

	if (ObjectiveWidget == nullptr)
	{
		APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
		ObjectiveWidget = CreateWidget<UObjectiveHUD>(PlayerController, ObjectiveWidgetClass);
	}

	if (ObjectiveWidget)
	{
		ObjectiveWidget->AddToViewport();
		
	}

	PlayerEnteredGame();
}


void AEscapeRoomGameMode::PlayerEnteredGame()
{
	ObjectiveWidget->SetNewObjective(FText::FromString("Locate Blue Button"), 0);
	ObjectiveWidget->SetNewObjective(FText::FromString("Unlock Blue Door"), 1);
	OnStartedEvent.Broadcast();
}
