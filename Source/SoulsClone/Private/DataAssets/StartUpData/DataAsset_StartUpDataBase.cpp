// Mahdiar Shoraka All Rights Reserved


#include "DataAssets/StartUpData/DataAsset_StartUpDataBase.h"

#include "AbilitySystem/SoulsAbilitySystemComponent.h"
#include "AbilitySystem/Abilities/SoulsGameplayAbility.h"

void UDataAsset_StartUpDataBase::GiveToAbilitySystemComponent(USoulsAbilitySystemComponent* InSoulsASCToGive,
	int32 ApplyLevel)
{
	check(InSoulsASCToGive);
	GrantAbilities(ActivateOnGivenAbilities, InSoulsASCToGive, ApplyLevel);
	GrantAbilities(ReactiveAbilities, InSoulsASCToGive, ApplyLevel);
}

void UDataAsset_StartUpDataBase::GrantAbilities(const TArray<TSubclassOf<USoulsGameplayAbility>>& InAbilitiesToGive, USoulsAbilitySystemComponent* InSoulsASCToGive, int32 ApplyLevel)
{
	if (InAbilitiesToGive.IsEmpty()) return;
	for (const TSubclassOf<USoulsGameplayAbility>& Ability : InAbilitiesToGive)
	{
		if (!Ability) continue;
		FGameplayAbilitySpec AbilitySpec(Ability);
		AbilitySpec.SourceObject = InSoulsASCToGive->GetAvatarActor();
		AbilitySpec.Level = ApplyLevel;
		InSoulsASCToGive->GiveAbility(AbilitySpec);
	}
}
