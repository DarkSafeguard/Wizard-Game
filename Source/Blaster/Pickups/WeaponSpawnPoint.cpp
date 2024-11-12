// Fill out your copyright notice in the Description page of Project Settings.


#include "WeaponSpawnPoint.h"
#include "Blaster/Weapon/Weapon.h"

AWeaponSpawnPoint::AWeaponSpawnPoint()
{ 	
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	bReplicates = true;
}

void AWeaponSpawnPoint::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AWeaponSpawnPoint::BeginPlay()
{
	Super::BeginPlay();
	StartSpawnWeaponTimer((AActor*)nullptr);

	SpawnTransform = GetActorTransform();
	SpawnTransform.SetLocation(SpawnTransform.GetLocation() + FVector(0.0f, 0.0f, SpawnLocationHeight));
}

void AWeaponSpawnPoint::SpawnWeapon()
{
	SpawnedWeapon = GetWorld()->SpawnActor<AWeapon>(WeaponClass, SpawnTransform);

	if (HasAuthority() && SpawnedWeapon)
	{
		SpawnedWeapon->OnDestroyed.AddDynamic(this, &AWeaponSpawnPoint::StartSpawnWeaponTimer);
	}
}

void AWeaponSpawnPoint::SpawnWeaponTimerFinished()
{
	if (HasAuthority())
	{
		SpawnWeapon();
	}
}

void AWeaponSpawnPoint::StartSpawnWeaponTimer(AActor* DestoyedActor)
{
	GetWorldTimerManager().SetTimer(
		SpawnWeaponTimer,
		this,
		&AWeaponSpawnPoint::SpawnWeaponTimerFinished,
		SpawnWeaponTime
	);
}
