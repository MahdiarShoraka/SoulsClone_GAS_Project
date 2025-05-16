// Mahdiar Shoraka All Rights Reserved


#include "AbilitySystem/Abilities/SoulsHeroGameplayAbility.h"
#include "Characters/SoulsHeroCharacter.h"
#include "Controllers/SoulsHeroController.h"
//#include "AbilitySystemComponent.h"

ASoulsHeroCharacter* USoulsHeroGameplayAbility::GetHeroCharacterFromActorInfo()
{
	if (!CachedSoulsHeroCharacter.IsValid())
	{
		CachedSoulsHeroCharacter = Cast<ASoulsHeroCharacter>(CurrentActorInfo->AvatarActor);
	}
	return CachedSoulsHeroCharacter.IsValid() ? CachedSoulsHeroCharacter.Get() : nullptr;
}

ASoulsHeroController* USoulsHeroGameplayAbility::GetHeroControllerFromActorInfo()
{
	if (!CachedSoulsHeroCharacter.IsValid())
	{
		CachedSoulsHeroController = Cast<ASoulsHeroController>(CurrentActorInfo->PlayerController);
	}
	return CachedSoulsHeroController.IsValid() ? CachedSoulsHeroController.Get() : nullptr;
}

UHeroCombatComponent* USoulsHeroGameplayAbility::GetHeroCombatComponentFromActorInfo()
{
	return GetHeroCharacterFromActorInfo()->GetHeroCombatComponent();
}
