// Mahdiar Shoraka All Rights Reserved


#include "Components/Combat/HeroCombatComponent.h"

#include "Items/Weapons/SoulsHeroWeapon.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "SoulsGameplayTags.h"

#include "SoulsDebugHelper.h"

ASoulsHeroWeapon* UHeroCombatComponent::GetHeroCarriedWeaponByTag(FGameplayTag InWeaponTag) const
{
	return Cast<ASoulsHeroWeapon>(GetCharacterCarriedWeaponByTag(InWeaponTag));
}

ASoulsHeroWeapon* UHeroCombatComponent::GetHeroCurrentEquippedWeapon() const
{
	return Cast<ASoulsHeroWeapon>(GetCharacterCurrentEquippedWeapon());
}

float UHeroCombatComponent::GetHeroCurrentEquippedWeaponDamageAtLevel(float InLevel) const
{
	return GetHeroCurrentEquippedWeapon()->HeroWeaponData.WeaponBaseDamage.GetValueAtLevel(InLevel);
}

void UHeroCombatComponent::OnHitTargetActor(AActor* HitActor)
{
	if (OverlappedActors.Contains(HitActor)) return; // damage the actor only once per attack
	OverlappedActors.AddUnique(HitActor);

	FGameplayEventData EventData;
	EventData.Instigator = GetOwningPawn();
	EventData.Target = HitActor;
	
	UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(
		GetOwningPawn(),
		SoulsGameplayTags::Shared_Event_MeleeHit,
		EventData);

	UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(
	GetOwningPawn(),
	SoulsGameplayTags::Player_Event_HitPause,
	FGameplayEventData());
}

void UHeroCombatComponent::OnWeaponPulledFromTargetActor(AActor* InteractedActor)
{
	UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(
	GetOwningPawn(),
	SoulsGameplayTags::Player_Event_HitPause,
	FGameplayEventData());
}
