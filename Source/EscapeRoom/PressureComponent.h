// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "Mover.h"
#include "Engine/StaticMesh.h"
#include "Materials/MaterialInterface.h"
#include "PressureComponent.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ESCAPEROOM_API UPressureComponent : public UBoxComponent
{
	GENERATED_BODY()

public:
	UPressureComponent();

protected:
	virtual void BeginPlay() override;

	

public:

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	void SetMover(UMover* Mover);

private:

	UPROPERTY(EditAnywhere, Category = "Trigger Settings")
	FName KeyName;

	UPROPERTY(EditAnywhere, Category = "Trigger Settings")
	bool IsAttachable = false;

	UPROPERTY(EditAnywhere, Category = "Trigger Settings")
	bool IsLockable = false;

	UPROPERTY(EditAnywhere, Category = "Trigger Settings")
	UMaterialInterface* OnLightMaterial;

	UPROPERTY(EditAnywhere, Category = "Trigger Settings")
	UMaterialInterface* OffLightMaterial;

	UMover* Mover;

	//functions
	AActor* GetUnlockActor() const;

	AActor* AttachedActor = nullptr;
	
};
