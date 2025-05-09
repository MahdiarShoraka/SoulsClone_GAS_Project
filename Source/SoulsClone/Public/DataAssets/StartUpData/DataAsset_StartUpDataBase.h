// Mahdiar Shoraka All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DataAsset_StartUpDataBase.generated.h"

class USoulsGameplayAbility;
class USoulsAbilitySystemComponent;

/**
 * 
 */
UCLASS()
class SOULSCLONE_API UDataAsset_StartUpDataBase : public UDataAsset
{
	GENERATED_BODY()

public:
	virtual void GiveToAbilitySystemComponent(USoulsAbilitySystemComponent* InSoulsASCToGive, int32 ApplyLevel = 1);
protected:
	UPROPERTY(EditDefaultsOnly, Category="StartUpData")
	TArray<TSubclassOf<USoulsGameplayAbility>> ActivateOnGivenAbilities;

	UPROPERTY(EditDefaultsOnly, Category="StartUpData")
	TArray<TSubclassOf<USoulsGameplayAbility>> ReactiveAbilities;

	void GrantAbilities(const TArray<TSubclassOf<USoulsGameplayAbility>>& InAbilitiesToGive, USoulsAbilitySystemComponent* InSoulsASCToGive, int32 ApplyLevel = 1); 
};
