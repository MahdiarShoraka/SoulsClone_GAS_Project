// Mahdiar Shoraka All Rights Reserved


#include "AbilitySystem/Abilities/SoulsEnemyGameplayAbility.h"

#include "Characters/SoulsEnemyCharacter.h"

ASoulsEnemyCharacter* USoulsEnemyGameplayAbility::GetEnemyCharacterFromActorInfo()
{
	if (!CachedSoulsEnemyCharacter.IsValid())
	{
		CachedSoulsEnemyCharacter = Cast<ASoulsEnemyCharacter>(CurrentActorInfo->AvatarActor);
	}
	return CachedSoulsEnemyCharacter.IsValid()? CachedSoulsEnemyCharacter.Get() : nullptr;
}

UEnemyCombatComponent* USoulsEnemyGameplayAbility::GetEnemyCombatComponentFromActorInfo()
{
	return GetEnemyCharacterFromActorInfo()->GetEnemyCombatComponent();
}
