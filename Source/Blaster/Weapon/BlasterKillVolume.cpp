// Fill out your copyright notice in the Description page of Project Settings.


#include "BlasterKillVolume.h"
#include "Blaster/Public/Character/BlasterCharacter.h"

// Sets default values
ABlasterKillVolume::ABlasterKillVolume()
{
    // Create the box component and set it as the root component
    CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionBox"));
    RootComponent = CollisionBox;

    // Set collision properties
    CollisionBox->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
    CollisionBox->SetCollisionObjectType(ECollisionChannel::ECC_WorldDynamic);
    CollisionBox->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);

    // Bind the overlap event
    CollisionBox->OnComponentBeginOverlap.AddDynamic(this, &ABlasterKillVolume::OnOverlapBegin);
    CollisionBox->OnComponentEndOverlap.AddDynamic(this, &ABlasterKillVolume::OnOverlapEnd);


    // Initialize the trigger flag
    bHasTriggered = false;
}

// Called when the game starts or when spawned
void ABlasterKillVolume::BeginPlay()
{
    Super::BeginPlay();
}

// Overlap event handler
void ABlasterKillVolume::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
    UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
    bool bFromSweep, const FHitResult& SweepResult)
{
    if (!bHasTriggered && OtherActor && OtherActor != this)
    {
        bHasTriggered = true; // Ensure this logic only executes once per overlap
        UE_LOG(LogTemp, Warning, TEXT("Overlap detected with: %s"), *OtherActor->GetName());

        // Your custom logic goes here
        ABlasterCharacter* BlasterCharacter = Cast<ABlasterCharacter>(OtherActor);
        if (BlasterCharacter)
        {
            UE_LOG(LogTemp, Warning, TEXT("BlasterCharacter overlapped with: %s"), *OtherActor->GetName());

            BlasterCharacter->Elim(false);
        }
    }
}

// Overlap end event handler
void ABlasterKillVolume::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
    UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
    if (OtherActor && OtherActor != this)
    {
        bHasTriggered = false; // Reset the trigger flag
        UE_LOG(LogTemp, Warning, TEXT("Overlap ended with: %s"), *OtherActor->GetName());
    }
}
