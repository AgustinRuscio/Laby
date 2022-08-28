
#include "PlayerBase.h"
#include "Engine/World.h"
#include "Components/InputComponent.h"
#include "LoseWidget.h"

APlayerBase::APlayerBase()
{
	PrimaryActorTick.bCanEverTick = true;

	health = 100;
	ReSpawns = 5;
	Velocity = 400;
	RotationVelocity = 150;
}

void APlayerBase::Tick(float DeltaTime)
{
	if (health <= 0)
	{
			ReSpawns--;
		if (ReSpawns > 0)
		{
			SetActorLocation(initialPosition);
			SetActorRotation(initialRotation);
			health = Initialhealth;
		}
		else
		{
			GetWorld()->ServerTravel("Lose");
		}
	}
}

void APlayerBase::BeginPlay()
{
	Super::BeginPlay();

	initialPosition = GetActorLocation();
	initialRotation = GetActorRotation();
	Initialhealth = health;
}

void APlayerBase::SetupPlayerInputComponent(UInputComponent* inputComponent)
{
	inputComponent->BindAxis("Vertical", this, &APlayerBase::VerticalAxis);
	inputComponent->BindAxis("Sides", this, &APlayerBase::SideAxis);
}

void APlayerBase::VerticalAxis(float Axis)
{
	FVector Movement;
	Movement.X = Axis*Velocity* GetWorld()->GetDeltaSeconds();
	AddActorLocalOffset(FVector(Movement), true);
}

void APlayerBase::SideAxis(float Axis)
{
	FRotator Rotation;
	Rotation.Yaw = Axis * RotationVelocity * GetWorld()->GetDeltaSeconds();
	AddActorLocalRotation(Rotation, true);
}