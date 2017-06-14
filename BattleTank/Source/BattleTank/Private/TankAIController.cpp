// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	ATank* PlayerTank = GetPlayerTank();
	if(PlayerTank)
	{
		FString PlayerTankName = PlayerTank->GetName();
		UE_LOG(LogTemp, Warning, TEXT("TankAIController - Found player tank: %s"), *PlayerTankName);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("TankAIController - No player tank found"));
	}

}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}


