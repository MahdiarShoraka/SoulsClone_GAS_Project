// Mahdiar Shoraka All Rights Reserved


#include "Components/Combat/PawnCombatComponent.h"

#include "Components/BoxComponent.h"
#include "Items/Weapons/SoulsWeaponBase.h"

#include "SoulsDebugHelper.h"

void UPawnCombatComponent::RegisterSpawnedWeapon(FGameplayTag InWeaponTagToRegister,
                                                 ASoulsWeaponBase* InWeaponToRegister, bool bRegisterAsEquippedWeapon)
{
	// WeaponTag must be new
	checkf(!CharacterCarriedWeaponMap.Contains(InWeaponTagToRegister), TEXT("A tag named %s has already been added as a carried weapon"), *InWeaponTagToRegister.ToString());
	check(InWeaponToRegister);

	// store tag and weapon as an entry inside the weapon map
	CharacterCarriedWeaponMap.Emplace(InWeaponTagToRegister, InWeaponToRegister);

	// callback list for the delegates
	InWeaponToRegister->OnWeaponHitTarget.BindUObject(this, &ThisClass::OnHitTargetActor);
	InWeaponToRegister->OnWeaponPulledFromTarget.BindUObject(this, &ThisClass::OnWeaponPulledFromTargetActor);

	if (bRegisterAsEquippedWeapon)
	{
		CurrentEquippedWeaponTag = InWeaponTagToRegister;
	}
}

ASoulsWeaponBase* UPawnCombatComponent::GetCharacterCarriedWeaponByTag(FGameplayTag InWeaponTagToGet) const
{
	if (CharacterCarriedWeaponMap.Contains(InWeaponTagToGet))
	{
		/* FoundWeapon is a pointer to a pointer to a weapon.
		 * The inner pointer (ASoulsWeaponBase*) can be used to access or change the weapon.
		 * but the outer pointer (FoundWeapon) cannot be changed to point to a different memory address.
		 */
		if (ASoulsWeaponBase* const* FoundWeapon = CharacterCarriedWeaponMap.Find(InWeaponTagToGet))
		{
			// dereference the outer pointer
			return *FoundWeapon;
		}
	}
	return nullptr;
}

ASoulsWeaponBase* UPawnCombatComponent::GetCharacterCurrentEquippedWeapon() const
{
	if (!CurrentEquippedWeaponTag.IsValid()) return nullptr;
	return GetCharacterCarriedWeaponByTag(CurrentEquippedWeaponTag);
}

void UPawnCombatComponent::ToggleWeaponCollision(bool bShouldEnable, EToggleDamageType ToggleDamageType)
{
	if (ToggleDamageType == EToggleDamageType::CurrentEquippedWeapon)
	{
		ASoulsWeaponBase* WeaponToToggle = GetCharacterCurrentEquippedWeapon();
		check(WeaponToToggle);
		if (bShouldEnable)
		{
			WeaponToToggle->GetWeaponCollisionBox()->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
		}
		else
		{
			WeaponToToggle->GetWeaponCollisionBox()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
			OverlappedActors.Empty();
		}
	}
}

void UPawnCombatComponent::OnHitTargetActor(AActor* HitActor)
{
}

void UPawnCombatComponent::OnWeaponPulledFromTargetActor(AActor* InteractedActor)
{
}
