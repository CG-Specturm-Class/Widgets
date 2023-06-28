// Fill out your copyright notice in the Description page of Project Settings.


#include "PressureComponent.h"


UPressureComponent::UPressureComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	
}


void UPressureComponent::BeginPlay()
{
	Super::BeginPlay();

	
}



void UPressureComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	
	
	AActor* Actor = GetUnlockActor();
	if (Actor != nullptr && Actor != AttachedActor)
	{
		
		UPrimitiveComponent* Component = Cast<UPrimitiveComponent>(Actor->GetRootComponent());
		if (Component != nullptr)
		{
			Component->SetSimulatePhysics(false);
		}

		//Attachable is set within trigger settings on specific objects
		//Attach messes up pickup ability
		if (IsAttachable)
		{
			Actor->AttachToComponent(this, FAttachmentTransformRules::KeepWorldTransform);
		}
		Mover->SetShouldMove(true);
		AttachedActor = Actor;
		
	}
	else if (Actor == nullptr && IsLockable)
	{
		Mover->SetShouldMove(false);
		AttachedActor = nullptr;
	}
}

void UPressureComponent::SetMover(UMover* NewMover)
{
	Mover = NewMover;
}

AActor* UPressureComponent::GetUnlockActor() const
{
	TArray<AActor*> Actors;
	GetOverlappingActors(Actors); //checking overlap actors

	for (AActor* Actor : Actors)
	{
		if (Actor->ActorHasTag(KeyName))
		{
			return Actor;
		}
	}

	return nullptr;
}