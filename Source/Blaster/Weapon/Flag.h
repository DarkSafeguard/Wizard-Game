// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Weapon.h"
#include "PhysicsEngine/PhysicsConstraintComponent.h"

#include "Flag.generated.h"

/**
 * 
 */
UCLASS()
class BLASTER_API AFlag : public AWeapon
{
	GENERATED_BODY()
	
public:
	AFlag();
	virtual void Dropped() override;
	void ResetFlag();

protected:
	virtual void OnEquipped() override;
	virtual void OnDropped() override;
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* FlagMesh;

	FTransform InitialTransform;

	UPhysicsConstraintComponent* PhysicsConstraint;

	void LockRotation();

	UFUNCTION(NetMulticast, Reliable)
	void MulticastResetFlag();

public:
	FORCEINLINE FTransform GetInitialTransform() const { return InitialTransform; }
};
