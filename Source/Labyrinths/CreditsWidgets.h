

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CreditsWidgets.generated.h"

/**
 * 
 */
UCLASS()
class LABYRINTHS_API UCreditsWidgets : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable)
	void backToMenu();
};