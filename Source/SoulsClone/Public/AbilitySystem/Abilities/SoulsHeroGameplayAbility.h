// Mahdiar Shoraka All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Abilities/SoulsGameplayAbility.h"
#include "SoulsHeroGameplayAbility.generated.h"

class ASoulsHeroCharacter;
class ASoulsHeroController;
class UHeroCombatComponent;

/**
 * 
 */
UCLASS()
class SOULSCLONE_API USoulsHeroGameplayAbility : public USoulsGameplayAbility
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category = "Souls|Ability")
	ASoulsHeroCharacter* GetHeroCharacterFromActorInfo();

	UFUNCTION(BlueprintPure, Category = "Souls|Ability")
	ASoulsHeroController* GetHeroControllerFromActorInfo();

	UFUNCTION(BlueprintPure, Category = "Souls|Ability")
	UHeroCombatComponent* GetHeroCombatComponentFromActorInfo();

	UFUNCTION(BlueprintPure, Category = "Souls|Ability")
	FGameplayEffectSpecHandle MakeHeroDamageEffectSpecHandle(TSubclassOf<UGameplayEffect> EffectClass, float InWeaponBaseDamage, FGameplayTag InCurrentAttackTypeTag, int32 InUsedComboCount);

private:
	TWeakObjectPtr<ASoulsHeroCharacter> CachedSoulsHeroCharacter;
	TWeakObjectPtr<ASoulsHeroController> CachedSoulsHeroController;
	
};
