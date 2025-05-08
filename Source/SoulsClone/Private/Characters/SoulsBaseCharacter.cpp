// Mahdiar Shoraka All Rights Reserved


#include "Characters/SoulsBaseCharacter.h"

// Sets default values
ASoulsBaseCharacter::ASoulsBaseCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	PrimaryActorTick.bStartWithTickEnabled = false;

	GetMesh()->bReceivesDecals = false;

}
