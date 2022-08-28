

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Door.generated.h"

UCLASS()
class LABYRINTHS_API ADoor : public AActor
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void OnOverlap(AActor* me, AActor* other);

	UPROPERTY(Editanywhere, Category = "sound")
		class USoundBase* DoorFX;

protected:
	void BeginPlay() override;
};
