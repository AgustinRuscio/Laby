

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Points.generated.h"

UCLASS()
class LABYRINTHS_API APoints : public AActor
{
	GENERATED_BODY()

protected:
	void BeginPlay()override;

private:

	UPROPERTY(Editanywhere, Category = "sound")
		class USoundBase* pointSF;

	UFUNCTION()
	void OnOverlap(AActor* me, AActor* other);
};
