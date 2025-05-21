// Mahdiar Shoraka All Rights Reserved


#include "AbilitySystem/SoulsAbilitySystemComponent.h"
#include "AbilitySystem/Abilities/SoulsGameplayAbility.h"
#include "Items/Weapons/SoulsHeroWeapon.h"

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

void USoulsAbilitySystemComponent::GrantHeroWeaponAbilities(
	const TArray<FSoulsHeroAbilitySet>& InDefaultWeaponAbilities, int32 ApplyLevel,
	TArray<FGameplayAbilitySpecHandle>& OutGrantedAbilitySpecHandles)
{
	if (InDefaultWeaponAbilities.IsEmpty()) return;
	for (const FSoulsHeroAbilitySet& AbilitySet : InDefaultWeaponAbilities)
	{
		if (!AbilitySet.IsValid()) continue;
		FGameplayAbilitySpec AbilitySpec(AbilitySet.AbilityToGrant);
		AbilitySpec.SourceObject = GetAvatarActor();
		AbilitySpec.Level = ApplyLevel;
		AbilitySpec.DynamicAbilityTags.AddTag(AbilitySet.InputTag);
		
		GiveAbility(AbilitySpec);

		OutGrantedAbilitySpecHandles.AddUnique(GiveAbility(AbilitySpec));
	}
}

void USoulsAbilitySystemComponent::RemoveGrantedHeroWeaponAbilities(ASoulsHeroWeapon* Weapon)
{
	TArray<FGameplayAbilitySpecHandle>& GrantedAbilitySpecHandles = Weapon->GetGrantedAbilitySpecHandles();

	if (GrantedAbilitySpecHandles.IsEmpty()) return;

	for (FGameplayAbilitySpecHandle& SpecHandle : GrantedAbilitySpecHandles)
	{
		if (SpecHandle.IsValid())
		{
			ClearAbility(SpecHandle);
		}
	}
	GrantedAbilitySpecHandles.Empty();
}
