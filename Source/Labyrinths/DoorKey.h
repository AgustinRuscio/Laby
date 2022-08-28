

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DoorKey.generated.h"

UCLASS()
class LABYRINTHS_API ADoorKey : public AActor
{
	GENERATED_BODY()

private:
	UFUNCTION()
		void OnOverlap(AActor* me, AActor* other);

protected:
	void BeginPlay() override;

	UPROPERTY(Editanywhere, Category = "sound")
		class USoundBase* keyFX;
};
