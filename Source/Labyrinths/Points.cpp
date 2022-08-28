

#include "Points.h"
#include "PlayerBase.h"
#include "Engine/World.h"
#include "LabyrinthsGameModeBase.h"
#include "Kismet/GameplayStatics.h"

void APoints::BeginPlay()
{
	Super::BeginPlay();
	OnActorBeginOverlap.AddDynamic(this, &APoints::OnOverlap);
}

void APoints::OnOverlap(AActor* me, AActor* other)
{
	APlayerBase* pb = Cast<APlayerBase>(other);
	if (pb != nullptr)
	{
		AGameModeBase* gameMode =GetWorld()->GetAuthGameMode();
		ALabyrinthsGameModeBase* GameMode = Cast<ALabyrinthsGameModeBase>(gameMode);
		if (gameMode!=nullptr)
		{
			GameMode->pickedObjectives++;

			UGameplayStatics::SpawnSoundAtLocation(this, pointSF, GetActorLocation() );
			
			Destroy();
		}
	}
}