// Mahdiar Shoraka All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Components/Combat/PawnCombatComponent.h"
#include "HeroCombatComponent.generated.h"

class ASoulsHeroWeapon;
/**
 * 
 */
UCLASS()
class SOULSCLONE_API UHeroCombatComponent : public UPawnCombatComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Souls|Combat")
	ASoulsHeroWeapon* GetHeroCarriedWeaponByTag(FGameplayTag InWeaponTag) const;

	UFUNCTION(BlueprintCallable, Category = "Souls|Combat")
	ASoulsHeroWeapon* GetHeroCurrentEquippedWeapon() const;

	UFUNCTION(BlueprintCallable, Category = "Souls|Combat")
	float GetHeroCurrentEquippedWeaponDamageAtLevel(float InLevel) const;
	
	virtual void OnHitTargetActor(AActor* HitActor) override;
	virtual void OnWeaponPulledFromTargetActor(AActor* InteractedActor) override;
};
