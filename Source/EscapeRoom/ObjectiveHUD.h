// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Styling/CoreStyle.h"
#include "Fonts/SlateFontInfo.h"
#include "Widgets/Text/STextBlock.h"
#include "ObjectiveHUD.generated.h"

/**
 * 
 */

class UTextBlock;
class UBackgroundBlur;
class UWidgetAnimation;

USTRUCT(BlueprintType)
struct FObjectiveText
{
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FText Title;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FText Descripton;
};




UCLASS()
class ESCAPEROOM_API UObjectiveHUD : public UUserWidget
{
	GENERATED_BODY()
	
public:

	void UpdateObjectiveText();

	UFUNCTION(BlueprintCallable, Category = "Objective Controls")
	void SetNewObjective(FText ObjectivesText, int32 ObjectiveNum);

	UFUNCTION(BlueprintCallable, Category = "Objective Controls")
	void CompleteObjective(int32 ObjectiveNum);

	UFUNCTION(BlueprintCallable, Category = "Objective Controls")
	void ClearObjective();

	UFUNCTION(BlueprintCallable, Category = "Objective Controls")
	void ToggleObjective(int32 ObjectiveNum, bool IsHidden, bool ClearOnHide);

	virtual void NativeOnInitialized() override;

protected:

public:
	

private:
	
	UPROPERTY(meta = (BindWidget))
	UTextBlock* ObjectiveText;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* ObjectiveTextTwo;

	UPROPERTY(meta = (BindWidget))
	UBackgroundBlur* ObjectiveBox;

	UPROPERTY(meta = (BindWidget))
	UBackgroundBlur* ObjectiveBoxTwo;

	UPROPERTY(BlueprintReadOnly, Transient, meta = (BindWidgetAnim, AllowPrivateAccess))
	UWidgetAnimation* FadeIn;

	UPROPERTY(BlueprintReadOnly, Transient, meta = (BindWidgetAnim, AllowPrivateAccess))
	UWidgetAnimation* FadeInTwo;

	//Functions
	/*UFUNCTION()
	FTextBlockStyle GetIncompleteStyle() { return IncompleteObjectiveTextFont; }*/
};
