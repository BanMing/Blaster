// Fill out your copyright notice in the Description page of Project Settings.

#include "BasterLobbyGameMode.h"

#include "GameFramework/GameStateBase.h"

void ABasterLobbyGameMode::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);

	int32 NumOfPlayers = GameState->PlayerArray.Num();
	if (NumOfPlayers == 2)
	{
		UWorld* World = GetWorld();
		if (World)
		{
			World->ServerTravel(FString("/Game/Maps/BlasterMap?listen"));
		}
	}
}
