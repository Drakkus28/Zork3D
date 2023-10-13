// Copyright Epic Games, Inc. All Rights Reserved.


#include "fpsproj_mrl0187GameModeBase.h"

#include "Engine.h"

Afpsproj_mrl0187GameModeBase::Afpsproj_mrl0187GameModeBase(const class FObjectInitializer& PCIP) : Super(PCIP)
{
	static ConstructorHelpers::FObjectFinder<UBlueprint>PlayerPawnObject(TEXT("Blueprint'/Game/FPSContent/Blueprints/BP_FPSCharacter.BP_FPSCharacter'"));

	if (PlayerPawnObject.Object != NULL)
	{
		DefaultPawnClass = (UClass*)PlayerPawnObject.Object->GeneratedClass;
	}
	static ConstructorHelpers::FObjectFinder<UBlueprint>PlayerController(TEXT("Blueprint'/Game/FPSContent/Blueprints/InvenController.InvenController'"));
	PlayerControllerClass = (UClass*)PlayerController.Object->GeneratedClass;
}

void Afpsproj_mrl0187GameModeBase::StartPlay()
{
	Super::StartPlay();

	if (GEngine)
	{
		//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("Hello world, this it mrl0187!"));
	}
}
