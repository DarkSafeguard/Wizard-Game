// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "WeaponSpawnPoint.generated.h"

/**
 * 
 */
UCLASS()
class BLASTER_API AWeaponSpawnPoint : public AActor
{
	GENERATED_BODY()
public:
	// Sets default values for this actor's properties
	AWeaponSpawnPoint();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class AWeapon> WeaponClass;

	UPROPERTY()
	AWeapon* SpawnedWeapon;
	UPROPERTY(EditAnywhere)
	float SpawnLocationHeight = 50.f;

	void SpawnWeapon();
	void SpawnWeaponTimerFinished();

	UFUNCTION()
	void StartSpawnWeaponTimer(AActor* DestoyedActor);

private:
	FTimerHandle SpawnWeaponTimer;
	FTransform SpawnTransform;

	UPROPERTY(EditAnywhere)
	float SpawnWeaponTime;

public:


};

