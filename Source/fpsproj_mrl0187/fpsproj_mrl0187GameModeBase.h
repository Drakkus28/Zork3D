// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "fpsproj_mrl0187GameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class FPSPROJ_MRL0187_API Afpsproj_mrl0187GameModeBase : public AGameModeBase
{
	GENERATED_BODY()
		virtual void StartPlay() override;
	Afpsproj_mrl0187GameModeBase(const class FObjectInitializer& PCIP);
};
