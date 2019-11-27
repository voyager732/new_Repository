// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameMode.h"
#include "ACharacter.h"
#include "APlayerController.h"

AMyGameMode::AMyGameMode()
{
	DefaultPawnClass = AACharacter::StaticClass();
	PlayerControllerClass = AAPlayerController::StaticClass();
}