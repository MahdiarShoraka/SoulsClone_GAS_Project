// Mahdiar Shoraka All Rights Reserved

#pragma once

#include "GameplayTagContainer.h"
#include "SoulsStructTypes.generated.h"

class UInputMappingContext;
class USoulsHeroLinkedAnimLayer;
class USoulsHeroGameplayAbility;

USTRUCT(BlueprintType)
struct FSoulsHeroAbilitySet
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (Categories = "InputTag"))
	FGameplayTag InputTag;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<USoulsHeroGameplayAbility> AbilityToGrant;

	bool IsValid() const;
};

USTRUCT(BlueprintType)
struct FSoulsHeroWeaponData
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<USoulsHeroLinkedAnimLayer> WeaponAnimLayerToLink;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UInputMappingContext* WeaponInputMappingContext = nullptr;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (TitleProperty = "InputTag"))
	TArray<FSoulsHeroAbilitySet> DefaultWeaponAbilities;
};