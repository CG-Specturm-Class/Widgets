// Fill out your copyright notice in the Description page of Project Settings.


#include "ObjectiveHUD.h"
#include "Components/TextBlock.h"
#include "UMG/Public/Components/BackgroundBlur.h"
#include "Fonts/SlateFontInfo.h"
#include "Styling/CoreStyle.h"
#include "Widgets/Text/STextBlock.h"

void UObjectiveHUD::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	//First objective
	ObjectiveText->SetText(FText::FromString(" "));
	ObjectiveBox->SetRenderOpacity(0.0f);

	//Second Objective
	ObjectiveTextTwo->SetText(FText::FromString(" "));
	ObjectiveBoxTwo->SetRenderOpacity(0.0f);

	ToggleObjective(0, true, true);
	ToggleObjective(1, true, true);
}

void UObjectiveHUD::SetNewObjective(FText ObjectivesText, int32 ObjectiveNum)
{
	FText LText = ObjectivesText;

	switch (ObjectiveNum) //cyclying for when there is more than one objective
	{
		case 0:
			ObjectiveText->SetText(LText);
			ObjectiveText->SetFont(FSlateFontInfo("Roboto", 20));
			ObjectiveText->SetColorAndOpacity(FLinearColor::White);
			break;
		case 1:
			ObjectiveTextTwo->SetText(LText);
			ObjectiveTextTwo->SetFont(FSlateFontInfo("Roboto", 20));
			ObjectiveTextTwo->SetColorAndOpacity(FLinearColor::White);
			break;
	}
}

void UObjectiveHUD::CompleteObjective(int32 ObjectiveNum)
{
	switch (ObjectiveNum)
	{
	case 0:
		ObjectiveText->SetFont(FSlateFontInfo("Roboto", 20));
		ObjectiveText->SetColorAndOpacity(FLinearColor::Green);
		break;
	case 1:
		ObjectiveTextTwo->SetFont(FSlateFontInfo("Roboto", 20));
		ObjectiveTextTwo->SetColorAndOpacity(FLinearColor::Green);
		break;
	}
}

void UObjectiveHUD::ClearObjective()
{
	ObjectiveText->SetText(FText::FromString(""));
	ObjectiveTextTwo->SetText(FText::FromString(""));
}

void UObjectiveHUD::ToggleObjective(int32 ObjectiveNum, bool IsHidden, bool ClearOnHide)
{
	if (IsHidden && ClearOnHide)
	{
		ClearObjective();
	}
	else
	{
		switch (ObjectiveNum)
		{
			case 0:
				if (IsHidden)
				{
					ObjectiveText->SetVisibility(ESlateVisibility::Hidden);
				}
				else
				{
					ObjectiveText->SetVisibility(ESlateVisibility::Visible);
				}
				break;
			case 1:
				if (IsHidden)
				{
					ObjectiveTextTwo->SetVisibility(ESlateVisibility::Hidden);
				}
				else
				{
					ObjectiveTextTwo->SetVisibility(ESlateVisibility::Visible);
				}
				break;
		}
	}
}

void UObjectiveHUD::UpdateObjectiveText()
{
	if (ObjectiveText)
	{
		FText NewObjectiveText = FText::FromString("OBJECTIVE: LOCATE BLUE BUTTON");
		ObjectiveText->SetText(NewObjectiveText);

		PlayAnimation(FadeIn, 0.0f, 1, EUMGSequencePlayMode::Forward, 4.0f);
	}
}