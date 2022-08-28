

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "VerticalTrap.generated.h"

UCLASS()
class LABYRINTHS_API AVerticalTrap : public AActor
{
	GENERATED_BODY()

protected:
	void BeginPlay() override;

public:	
	AVerticalTrap();

	void Tick(float deltaTime) override;
	void TrapMovement();

	UFUNCTION()
	void OnOverlap(AActor* me, AActor* Other);

	FTimerHandle FallTimer;

	UPROPERTY(EditAnywhere)
		float ChangeTime;

	UPROPERTY(EditAnywhere)
		float velocity;

	UPROPERTY(EditAnywhere)
		float Damage;

	UPROPERTY(Editanywhere, Category = "sound")
		class USoundBase* damageFX;
};
