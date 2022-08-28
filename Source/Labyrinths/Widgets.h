

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Widgets.generated.h"

/**
 * 
 */
UCLASS()
class LABYRINTHS_API UWidgets : public UUserWidget
{
	GENERATED_BODY()

public:
		UFUNCTION(BlueprintCallable)
		void Play();

		UFUNCTION(BlueprintCallable)
		void QuitGame();

		UFUNCTION(BlueprintCallable)
		void Credits();
};
