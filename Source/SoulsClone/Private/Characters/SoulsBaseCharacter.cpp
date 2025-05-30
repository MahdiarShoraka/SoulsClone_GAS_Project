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

UPawnCombatComponent* ASoulsBaseCharacter::GetPawnCombatComponent() const
{
	return nullptr;
}

UPawnUIComponent* ASoulsBaseCharacter::GetPawnUIComponent() const
{
	return nullptr;
}

void ASoulsBaseCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	
	if (SoulsAbilitySystemComponent)
	{
		SoulsAbilitySystemComponent->InitAbilityActorInfo(this,this);
		ensureMsgf(!CharacterStartUpData.IsNull(), TEXT("Forgot to assign start up data to %s"), *GetName());
	}
}
