

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "LoseWidget.generated.h"

/**
 * 
 */
UCLASS()
class LABYRINTHS_API ULoseWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:

	UFUNCTION(BlueprintCallable)
		void TryAgainButton();

	UFUNCTION(BlueprintCallable)
		void QuitGame();
};
