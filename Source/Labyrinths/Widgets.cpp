
#include "Widgets.h"
#include "Engine/World.h"
#include "GenericPlatform/GenericPlatformMisc.h"

void UWidgets::Play()
{
	GetWorld()->ServerTravel("Level");
}

void UWidgets::QuitGame()
{
	
}

void UWidgets::Credits()
{
	GetWorld()->ServerTravel("Credits");
}