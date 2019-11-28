// Fill out your copyright notice in the Description page of Project Settings.


#include "ABGameMode.h"
#include "ABPlayerController.h"
#include "PlayerCharacter.h"

AABGameMode::AABGameMode()
{
	DefaultPawnClass = APlayerCharacter::StaticClass();
	PlayerControllerClass = APlayerController::StaticClass();
}
