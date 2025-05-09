// Mahdiar Shoraka All Rights Reserved


#include "Characters/SoulsBaseCharacter.h"
#include "Components/SkeletalMeshComponent.h"
#include "AbilitySystem/SoulsAbilitySystemComponent.h"
#include "AbilitySystem/SoulsAttributeSet.h"

// Sets default values
ASoulsBaseCharacter::ASoulsBaseCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	PrimaryActorTick.bStartWithTickEnabled = false;

	GetMesh()->bReceivesDecals = false;

	SoulsAbilitySystemComponent = CreateDefaultSubobject<USoulsAbilitySystemComponent>(TEXT("SoulsAbilitySystemComponent"));

	SoulsAttributeSet = CreateDefaultSubobject<USoulsAttributeSet>(TEXT("SoulsAttributeSet"));
}

UAbilitySystemComponent* ASoulsBaseCharacter::GetAbilitySystemComponent() const
{
	return GetSoulsAbilitySystemComponent();
}

void ASoulsBaseCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	
	if (SoulsAbilitySystemComponent)
	{
		SoulsAbilitySystemComponent->InitAbilityActorInfo(this,this);	
	}
}
