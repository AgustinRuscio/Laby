
#include "Checkpoint.h"
#include "PlayerBase.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"

void ACheckpoint::BeginPlay()
{
	Super::BeginPlay();
	OnActorBeginOverlap.AddDynamic(this, &ACheckpoint::OnOverlap);
}

void ACheckpoint::OnOverlap(AActor* me, AActor* other)
{
	APlayerBase* pb = Cast<APlayerBase>(other);
	if (pb != nullptr && pb->currentCheckpoint != this)
	{
		pb->initialPosition = GetActorLocation();
		pb->initialRotation = GetActorRotation();
		UGameplayStatics::SpawnSoundAtLocation(this, CheckpointFX, GetActorLocation());

		if (pb->currentCheckpoint != nullptr)
			pb->currentCheckpoint->AddActorLocalOffset(FVector(0,0,30));
		
			pb->currentCheckpoint = this;
			AddActorLocalOffset(FVector(0,0, -30));
		
	}
}