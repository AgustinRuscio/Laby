

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Checkpoint.generated.h"

UCLASS()
class LABYRINTHS_API ACheckpoint : public AActor
{
	GENERATED_BODY()

protected:
	void BeginPlay() override;

public:
	UFUNCTION()
	void OnOverlap(AActor* me, AActor* other);

	UPROPERTY(Editanywhere, Category = "sound")
		class USoundBase* CheckpointFX;
};