

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PlayerBase.generated.h"

UCLASS()
class LABYRINTHS_API APlayerBase : public APawn
{
	GENERATED_BODY()

protected:
	void BeginPlay() override;

/*public:
	void SaveGameLogic(float dTime);
	void LoadGameLogic(float dTime);
	bool canSaveGame;

	void InitSaveGame();
	void InitLoadGame();

	UPROPERTY()
		FDateTime SaveGameTime;*/


public:

	APlayerBase();

	FVector initialPosition;
	FRotator initialRotation;

	class ACheckpoint* currentCheckpoint;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float Initialhealth;

	UPROPERTY(BlueprintReadWrite)
	int KeysCollected;

	UPROPERTY(EditAnywhere, BlueprintReadOnly) 
		float health;

	UPROPERTY(EditAnywhere)
		float Velocity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int ReSpawns;

	UPROPERTY(EditAnywhere)
		float RotationVelocity;

	void SetupPlayerInputComponent(class UInputComponent* inputComponent) override;
	void Tick(float DeltaTime) override;

	void VerticalAxis(float Axis);
	void SideAxis(float Axis);
};
