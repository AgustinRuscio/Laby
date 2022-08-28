
#include "DoorKey.h"
#include "PlayerBase.h"
#include "Kismet/GameplayStatics.h"

void ADoorKey::BeginPlay()
{
	Super::BeginPlay();
	OnActorBeginOverlap.AddDynamic(this, &ADoorKey::OnOverlap);
}

void ADoorKey::OnOverlap(AActor* me, AActor* other)
{
	APlayerBase* pb = Cast<APlayerBase>(other);
	if (pb != nullptr)
	{
		pb->KeysCollected++;
		UGameplayStatics::SpawnSoundAtLocation(this, keyFX, GetActorLocation());
		Destroy();
	}
}