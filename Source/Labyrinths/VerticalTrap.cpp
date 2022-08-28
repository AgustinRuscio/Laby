
#include "VerticalTrap.h"
#include "TimerManager.h"
#include "PlayerBase.h"
#include "Kismet/GameplayStatics.h"

AVerticalTrap::AVerticalTrap()
{
	Damage = 25;

	PrimaryActorTick.bCanEverTick = true;
}

void AVerticalTrap::BeginPlay()
{
	Super::BeginPlay();

	GetWorldTimerManager().SetTimer(FallTimer, this, &AVerticalTrap::TrapMovement, ChangeTime, true);
	OnActorBeginOverlap.AddDynamic(this, &AVerticalTrap::OnOverlap);
}

void AVerticalTrap::Tick(float deltaTime)
{
	FVector movement (0,0,0);
	movement.Z = velocity*deltaTime;
	AddActorLocalOffset(movement, true);
}

void AVerticalTrap::TrapMovement()
{
	velocity *= -1;
}

void AVerticalTrap::OnOverlap(AActor*me, AActor* Other)
{
	APlayerBase* pb = Cast<APlayerBase>(Other);
	if (pb != nullptr)
	{
		UGameplayStatics::SpawnSoundAtLocation(this, damageFX, GetActorLocation());
		pb->health-=Damage;
	}
}