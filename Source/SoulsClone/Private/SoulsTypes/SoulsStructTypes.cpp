// Mahdiar Shoraka All Rights Reserved


#include "SoulsTypes/SoulsStructTypes.h"

#include "AbilitySystem/Abilities/SoulsGameplayAbility.h"

bool FSoulsHeroAbilitySet::IsValid() const
{
	return InputTag.IsValid() && AbilityToGrant;
}
