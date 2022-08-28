

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "LabyrinthsGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class LABYRINTHS_API ALabyrinthsGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
protected:
	void BeginPlay() override;

public:
	UPROPERTY(EditAnywhere)
		FString NextLevel;
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PointsNeededToWin;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	int pickedObjectives;

	ALabyrinthsGameModeBase();
	void Tick(float deltaTime) override;
};