// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSCharacter.h"
#include "Engine.h"

// Sets default values
AFPSCharacter::AFPSCharacter()
{

 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	// Create a first person camera component.
	FPSCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	// Attach the camera component to our capsule component. 
	FPSCameraComponent->SetupAttachment(GetCapsuleComponent());
	// Position the camera slightly above the eyes. 
	FPSCameraComponent->SetRelativeLocation(FVector(0.0f, 0.0f, 50.0f + BaseEyeHeight));
	// Allow the pawn to control camera rotation. 
	FPSCameraComponent->bUsePawnControlRotation = true;

	FPSMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("FirstPersonMesh"));
	// Only the owning player sees this mesh.
	FPSMesh->SetOnlyOwnerSee(true);
	// Attach the FPS mesh to the FPS camera. 
	FPSMesh->SetupAttachment(FPSCameraComponent);
	// Disable some environmental shadowing to preserve the illusion of having a single mesh.
		FPSMesh->bCastDynamicShadow = false;
	FPSMesh->CastShadow = false;
}

// Called when the game starts or when spawned
void AFPSCharacter::BeginPlay()
{
	Super::BeginPlay();
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, TEXT(""));
	}
}

// Called every frame
void AFPSCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AFPSCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	InputComponent->BindAxis("MoveForward", this, &AFPSCharacter::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &AFPSCharacter::MoveRight);
	InputComponent->BindAxis("Turn", this, &AFPSCharacter::AddControllerYawInput);
	InputComponent->BindAxis("LookUp", this, &AFPSCharacter::AddControllerPitchInput);
	InputComponent->BindAction("Jump", IE_Pressed, this, &AFPSCharacter::onStartJump);
	InputComponent->BindAction("Jump", IE_Released, this, &AFPSCharacter::onStopJump);

}

void AFPSCharacter::MoveForward(float val)
{
	if ((Controller != NULL) && (val != 0.0f))
	{
		FRotator Rotation = Controller->GetControlRotation();
		if (GetCharacterMovement()->IsMovingOnGround() || GetCharacterMovement()->IsFalling())
		{
			Rotation.Pitch = 0.0f;
		}
		FVector Direction = FRotationMatrix(Rotation).GetScaledAxis(EAxis::X);
		/*if (!bOnLadder)
		{
		GetCharacterMovement()->SetMovementMode(EMovementMode::MOVE_Walking);
		Direction = FRotationMatrix(Rotation).GetScaledAxis(EAxis::X);
		}
		else
		{
		GetCharacterMovement()->SetMovementMode(EMovementMode::MOVE_Flying);
		Direction = FRotationMatrix(Rotation).GetScaledAxis(EAxis::Z);
		}*/
		AddMovementInput(Direction, val);
	}
}

void AFPSCharacter::MoveRight(float val)
{
	if ((Controller != NULL) && (val != 0.0f))
	{
		FRotator Rotation = Controller->GetControlRotation();
		const FVector Direction = FRotationMatrix(Rotation).GetScaledAxis(EAxis::Y);
		AddMovementInput(Direction, val);
	}
}

void AFPSCharacter::onStartJump()
{
	bPressedJump = true;
}

void AFPSCharacter::onStopJump()
{
	bPressedJump = false;
}

/*
void AFPSCharacter::onStartLadderCollide()
{
	bOnLadder = true;
}

void AFPSCharacter::onStopLadderCollide()
{
	bOnLadder = false;
}
*/