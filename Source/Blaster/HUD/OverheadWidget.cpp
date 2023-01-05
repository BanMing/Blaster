// Fill out your copyright notice in the Description page of Project Settings.

#include "OverheadWidget.h"

#include "Components/TextBlock.h"
#include "GameFramework/PlayerState.h"

void UOverheadWidget::SetDisplayText(FString TextToDisplay)
{
	if (DisplayText)
	{
		DisplayText->SetText(FText::FromString(TextToDisplay));
	}
}

void UOverheadWidget::ShowPlayerNetRole(APawn* InPawn)
{
	APlayerState* PlayerState = InPawn->GetPlayerState();

	ENetRole LocalRole = InPawn->GetLocalRole();
	ENetRole RemoteRole = InPawn->GetRemoteRole();
	FString Role = GetNetRoleString(LocalRole);

	// FString RoleString = FString::Printf(TEXT("%s\nLocal Role: [%s]\nRemote Role: [%s]"), *PlayerState->GetPlayerName(), *GetNetRoleString(LocalRole), *GetNetRoleString(RemoteRole));
	FString RoleString = FString::Printf(TEXT("Local Role: [%s]\nRemote Role: [%s]"), *GetNetRoleString(LocalRole), *GetNetRoleString(RemoteRole));
	SetDisplayText(RoleString);
}

void UOverheadWidget::NativeDestruct()
{
	RemoveFromParent();

	Super::NativeDestruct();
}

FString UOverheadWidget::GetNetRoleString(ENetRole NetRole)
{
	FString Role;
	switch (NetRole)
	{
		case ROLE_None:
			Role = FString("None");
			break;
		case ROLE_SimulatedProxy:
			Role = FString("Simulated Proxy");
			break;
		case ROLE_AutonomousProxy:
			Role = FString("Autonomous Proxy");

			break;
		case ROLE_Authority:
			Role = FString("Authority");
			break;
	}

	return Role;
}
