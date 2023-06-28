// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Blueprint/UserWidget.h"
#include "EscapeRoomGameMode.generated.h"

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
	UUserWidget* ObjectiveWidget = nullptr;
};



