// Fill out your copyright notice in the Description page of Project Settings.

#include "LobbyGameMode.h"

#include "GameFramework/GameStateBase.h"
#include "GameFramework/PlayerState.h"

void ALobbyGameMode::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);

	if (GameState)
	{
		int32 NumOfPlayers = GameState->PlayerArray.Num();

		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(1, 60.0f, FColor::Yellow, FString::Printf(TEXT("Players in game %d"), NumOfPlayers));
			APlayerState* PlayerState = NewPlayer->GetPlayerState<APlayerState>();
			if (PlayerState)
			{
				FString PlayerName = PlayerState->GetPlayerName();
				GEngine->AddOnScreenDebugMessage(-1, 60.0f, FColor::Cyan, FString::Printf(TEXT("%s has joined the game!"), *PlayerName));
			}
		}
	}
}

void ALobbyGameMode::Logout(AController* Exiting)
{
	Super::Logout(Exiting);

	int32 NumOfPlayers = GameState->PlayerArray.Num();

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(1, 60.0f, FColor::Yellow, FString::Printf(TEXT("Players in game %d"), NumOfPlayers - 1));
		APlayerState* PlayerState = Exiting->GetPlayerState<APlayerState>();
		if (PlayerState)
		{
			FString PlayerName = PlayerState->GetPlayerName();
			GEngine->AddOnScreenDebugMessage(-1, 60.0f, FColor::Cyan, FString::Printf(TEXT("%s has left the game!"), *PlayerName));
		}
	}
}
