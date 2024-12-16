// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"

#include "BlasterKillVolume.generated.h"

UCLASS()
class BLASTER_API ABlasterKillVolume : public AActor
{
    GENERATED_BODY()

public:
    ABlasterKillVolume();

protected:
    virtual void BeginPlay() override;

private:
    // Box component for collision
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Collision", meta = (AllowPrivateAccess = "true"))
    UBoxComponent* CollisionBox;

    // Function to handle collision
    UFUNCTION()
    void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
        UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
        bool bFromSweep, const FHitResult& SweepResult);

    // Function to handle overlap end
    UFUNCTION()
    void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
        UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

    // Boolean to ensure the method is only called once
    bool bHasTriggered;
};
