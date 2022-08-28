
#include "Door.h"
#include "PlayerBase.h"
#include "Kismet/GameplayStatics.h"

void ADoor::BeginPlay()
{
	Super::BeginPlay();
	OnActorBeginOverlap.AddDynamic(this, &ADoor::OnOverlap);
}

void ADoor::OnOverlap(AActor*me, AActor*other)
{
	APlayerBase* pb = Cast<APlayerBase>(other);
	if (pb != nullptr && pb->KeysCollected > 0)
	{
		pb->KeysCollected--;
		UGameplayStatics::SpawnSoundAtLocation(this, DoorFX, GetActorLocation());
		Destroy();
	}
}