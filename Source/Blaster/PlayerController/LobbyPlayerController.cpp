// Fill out your copyright notice in the Description page of Project Settings.


#include "LobbyPlayerController.h"
#include "Components/InputComponent.h"
#include "Blaster/HUD/ReturnToMainMenu.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"


void ALobbyPlayerController::ShowReturnToMainMenu()
{
	UE_LOG(LogTemp, Warning, TEXT("ShowReturnToMainMenu after 'P' pressed"), 10);
	if (ReturnToMainMenuWidget == nullptr) return;
	if (ReturnToMainMenu == nullptr)
	{
		ReturnToMainMenu = CreateWidget<UReturnToMainMenu>(this, ReturnToMainMenuWidget);
	}
	if (ReturnToMainMenu)
	{
		bReturnToMainMenuOpen = !bReturnToMainMenuOpen;
		if (bReturnToMainMenuOpen)
		{
			ReturnToMainMenu->MenuSetup();
		}
		else
		{
			ReturnToMainMenu->MenuTearDown();
		}
	}
}

void ALobbyPlayerController::SetupInputComponent()
{

	Super::SetupInputComponent();

	if (InputComponent == nullptr) return;
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent))
	{
		EnhancedInputComponent->BindAction(QuitAction, ETriggerEvent::Completed, this, &ALobbyPlayerController::ShowReturnToMainMenu);
	}
}