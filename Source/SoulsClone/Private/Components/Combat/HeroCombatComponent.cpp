// Mahdiar Shoraka All Rights Reserved


#include "Components/Combat/HeroCombatComponent.h"

#include "Items/Weapons/SoulsHeroWeapon.h"

ASoulsHeroWeapon* UHeroCombatComponent::GetHeroCarriedWeaponByTag(FGameplayTag InWeaponTag) const
{
	return Cast<ASoulsHeroWeapon>(GetCharacterCarriedWeaponByTag(InWeaponTag));
}
