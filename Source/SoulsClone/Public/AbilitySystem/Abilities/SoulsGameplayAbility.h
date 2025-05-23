// Mahdiar Shoraka All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "SoulsTypes/SoulsEnumTypes.h"
#include "SoulsGameplayAbility.generated.h"

class UPawnCombatComponent;
class USoulsAbilitySystemComponent;

UENUM(BlueprintType)
enum class ESoulsAbilityActivationPolicy : uint8
{
	OnTriggered,
	OnGiven
};
/**
 * Base Gameplay Ability class - Provides helper functions
 */
UCLASS()
class SOULSCLONE_API USoulsGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()

protected:
	//~ Begin UGameplayAbility Interface
	virtual void OnGiveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec) override;
	virtual void EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled) override;
	//~ End UGameplayAbility Interface
	
	UPROPERTY(EditDefaultsOnly, Category = "Souls|Ability")
	ESoulsAbilityActivationPolicy AbilityActivationPolicy = ESoulsAbilityActivationPolicy::OnTriggered;

	UFUNCTION(BlueprintPure, Category = "Souls|Ability")
	UPawnCombatComponent* GetPawnCombatComponentFromActorInfo() const;

	UFUNCTION(BlueprintPure, Category = "Souls|Ability")
	USoulsAbilitySystemComponent* GetSoulsAbilitySystemComponentFromActorInfo() const;

	FActiveGameplayEffectHandle NativeApplyEffectSpecHandleToTarget(AActor* TargetActor, const FGameplayEffectSpecHandle InSpecHandle);

	UFUNCTION(BlueprintCallable, Category = "Souls|Ability", meta = (DisplayName = "Apply Gameplay Effect Spec Handle To Target Actor" , ExpandEnumAsExecs = "OutSuccessType"))
	FActiveGameplayEffectHandle BP_ApplyEffectSpecHandleToTarget(AActor* TargetActor, const FGameplayEffectSpecHandle InSpecHandle, ESoulsSuccessType& OutSuccessType);
};
