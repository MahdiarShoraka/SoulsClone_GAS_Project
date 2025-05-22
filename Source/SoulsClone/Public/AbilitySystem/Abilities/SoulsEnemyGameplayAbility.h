// Mahdiar Shoraka All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Abilities/SoulsGameplayAbility.h"
#include "SoulsEnemyGameplayAbility.generated.h"

class UEnemyCombatComponent;
class ASoulsEnemyCharacter;
/**
 * 
 */
UCLASS()
class SOULSCLONE_API USoulsEnemyGameplayAbility : public USoulsGameplayAbility
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category = "Souls|Ability")
	ASoulsEnemyCharacter* GetEnemyCharacterFromActorInfo();

	UFUNCTION(BlueprintPure, Category = "Souls|Ability")
	UEnemyCombatComponent* GetEnemyCombatComponentFromActorInfo();

private:
	TWeakObjectPtr<ASoulsEnemyCharacter> CachedSoulsEnemyCharacter;
};
