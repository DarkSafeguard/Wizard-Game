// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Pickup.h"
#include "SpeedPickup.generated.h"

/**
 * 
 */
UCLASS()
class BLASTER_API ASpeedPickup : public APickup
{
	GENERATED_BODY()

public:

protected:
	virtual void OnSphereOverlap(
		UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult);

private:

	UPROPERTY(EditAnywhere)
	float BaseSpeedBuff = 900.f;

	UPROPERTY(EditAnywhere)
	float CrouchSpeedBuff = 450.f;

	UPROPERTY(EditAnywhere)
	float SpeedBuffTime = 6.f;
};
