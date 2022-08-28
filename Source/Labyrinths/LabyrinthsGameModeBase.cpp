
#include "LabyrinthsGameModeBase.h"
#include "Engine/World.h"
#include "GameFramework/SaveGame.h"
#include "GameFramework/AsyncActionHandleSaveGame.h"

ALabyrinthsGameModeBase::ALabyrinthsGameModeBase()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ALabyrinthsGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	pickedObjectives = 0;	
}

void ALabyrinthsGameModeBase::Tick(float DeltaTime)
{
	if (pickedObjectives>=PointsNeededToWin)
	{
		GetWorld()->ServerTravel(NextLevel);
	}
}