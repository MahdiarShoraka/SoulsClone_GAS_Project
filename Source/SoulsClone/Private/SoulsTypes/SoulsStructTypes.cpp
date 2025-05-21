// Mahdiar Shoraka All Rights Reserved


#include "SoulsTypes/SoulsStructTypes.h"

#include "AbilitySystem/Abilities/SoulsHeroGameplayAbility.h"

bool FSoulsHeroAbilitySet::IsValid() const
{
	return InputTag.IsValid() && AbilityToGrant;
}
