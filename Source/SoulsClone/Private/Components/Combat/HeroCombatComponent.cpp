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

void UHeroCombatComponent::OnHitTargetActor(AActor* HitActor)
{
	if (OverlappedActors.Contains(HitActor)) // damage the actor only once per attack
	{
		return;
	}
	OverlappedActors.AddUnique(HitActor);

	FGameplayEventData EventData;
	EventData.Instigator = GetOwningPawn();
	EventData.Target = HitActor;
	
	UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(
		GetOwningPawn(),
		SoulsGameplayTags::Shared_Event_MeleeHit,
		EventData);
}

void UHeroCombatComponent::OnWeaponPulledFromTargetActor(AActor* InteractedActor)
{
	
}
