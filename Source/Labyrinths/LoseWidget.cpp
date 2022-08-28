
#include "LoseWidget.h"
#include "Engine/World.h"
#include "PlayerBase.h"

void ULoseWidget::TryAgainButton()
{
	GetWorld()->ServerTravel("Level1"); 
}

void ULoseWidget::QuitGame()
{
	exit(0);
}