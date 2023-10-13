// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "FPSCharacter.generated.h"

UCLASS()
class FPSPROJ_MRL0187_API AFPSCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AFPSCharacter();

	UPROPERTY(VisibleAnywhere) class UCameraComponent* FPSCameraComponent;
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh) USkeletalMeshComponent* FPSMesh;
	//UPROPERTY(bOnLadder) bool bOnLadder;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
		void MoveForward(float val);
	UFUNCTION()
		void MoveRight(float val);
	UFUNCTION()
		void onStartJump();
	UFUNCTION()
		void onStopJump();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
