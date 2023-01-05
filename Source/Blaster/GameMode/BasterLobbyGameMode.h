// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "BasterLobbyGameMode.generated.h"

/**
 * 
 */
UCLASS()
class BLASTER_API ABasterLobbyGameMode : public AGameMode
{
	GENERATED_BODY()
	public:
	virtual void PostLogin(APlayerController* NewPlayer) override;
	//virtual void Logout(AController* Exiting) override;
};
