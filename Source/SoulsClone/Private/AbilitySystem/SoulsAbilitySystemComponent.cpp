// Mahdiar Shoraka All Rights Reserved


#include "AbilitySystem/SoulsAbilitySystemComponent.h"

void USoulsAbilitySystemComponent::OnAbilityInputPressed(const FGameplayTag& InInputTag)
{
	if (!InInputTag.IsValid()) return;
	for (FGameplayAbilitySpec& AbilitySpec : GetActivatableAbilities())
	{
		if (!AbilitySpec.DynamicAbilityTags.HasTagExact(InInputTag)) continue;
		TryActivateAbility(AbilitySpec.Handle);
	}
}

void USoulsAbilitySystemComponent::OnAbilityInputReleased(const FGameplayTag& InInputTag)
{
}
