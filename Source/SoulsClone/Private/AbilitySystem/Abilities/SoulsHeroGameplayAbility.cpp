// Mahdiar Shoraka All Rights Reserved


#include "AbilitySystem/Abilities/SoulsHeroGameplayAbility.h"

#include "AbilitySystem/SoulsAbilitySystemComponent.h"
#include "Characters/SoulsHeroCharacter.h"
#include "Controllers/SoulsHeroController.h"
#include "SoulsGameplayTags.h"

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
	if (!CachedSoulsHeroController.IsValid())
	{
		CachedSoulsHeroController = Cast<ASoulsHeroController>(CurrentActorInfo->PlayerController);
	}
	return CachedSoulsHeroController.IsValid() ? CachedSoulsHeroController.Get() : nullptr;
}

UHeroCombatComponent* USoulsHeroGameplayAbility::GetHeroCombatComponentFromActorInfo()
{
	return GetHeroCharacterFromActorInfo()->GetHeroCombatComponent();
}

FGameplayEffectSpecHandle USoulsHeroGameplayAbility::MakeHeroDamageEffectSpecHandle(
	TSubclassOf<UGameplayEffect> EffectClass, float InWeaponBaseDamage, FGameplayTag InCurrentAttackTypeTag,
	int32 InCurrentComboCount)
{
	check(EffectClass);

	FGameplayEffectContextHandle ContextHandle = GetSoulsAbilitySystemComponentFromActorInfo()->MakeEffectContext();
	ContextHandle.SetAbility(this);
	ContextHandle.AddSourceObject(GetAvatarActorFromActorInfo());
	ContextHandle.AddInstigator(GetAvatarActorFromActorInfo(), GetAvatarActorFromActorInfo());
	
	FGameplayEffectSpecHandle EffectSpecHandle = GetSoulsAbilitySystemComponentFromActorInfo()->MakeOutgoingSpec(
		EffectClass, GetAbilityLevel(), ContextHandle);

	EffectSpecHandle.Data->SetSetByCallerMagnitude(SoulsGameplayTags::Shared_SetByCaller_BaseDamage, InWeaponBaseDamage);
	if (InCurrentAttackTypeTag.IsValid())
	{
		EffectSpecHandle.Data->SetSetByCallerMagnitude(InCurrentAttackTypeTag, InCurrentComboCount);
	}
	return EffectSpecHandle;
}
