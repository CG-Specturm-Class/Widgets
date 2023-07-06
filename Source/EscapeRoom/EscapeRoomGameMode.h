// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Blueprint/UserWidget.h"
#include "ObjectiveHUD.h"
#include "EscapeRoomGameMode.generated.h"

DECLARE_EVENT(EscapeRoomGameMode, FGameStarted);


UCLASS(minimalapi)
class AEscapeRoomGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AEscapeRoomGameMode();

	void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UUserWidget> ObjectiveWidgetClass;

	UPROPERTY()
	UObjectiveHUD* ObjectiveWidget = nullptr;


	FGameStarted OnStartedEvent;


	//functions
	void PlayerEnteredGame();
};



