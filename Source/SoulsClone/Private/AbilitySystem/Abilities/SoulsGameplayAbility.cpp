// Mahdiar Shoraka All Rights Reserved

#include "AbilitySystem/Abilities/SoulsGameplayAbility.h"
#include "AbilitySystem/SoulsAbilitySystemComponent.h"
#include "Components/Combat/PawnCombatComponent.h"
#include "AbilitySystemBlueprintLibrary.h"

void USoulsGameplayAbility::OnGiveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec)
{
	Super::OnGiveAbility(ActorInfo, Spec);

	if (AbilityActivationPolicy == ESoulsAbilityActivationPolicy::OnGiven)
	{
		if (ActorInfo && !Spec.IsActive())
		{
			ActorInfo->AbilitySystemComponent->TryActivateAbility(Spec.Handle);
		}
	}
}

void USoulsGameplayAbility::EndAbility(const FGameplayAbilitySpecHandle Handle,
	const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo,
	bool bReplicateEndAbility, bool bWasCancelled)
{
	Super::EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);

	if (AbilityActivationPolicy == ESoulsAbilityActivationPolicy::OnGiven)
	{
		if (ActorInfo)
		{
			ActorInfo->AbilitySystemComponent->ClearAbility(Handle);
		}
	}
}

UPawnCombatComponent* USoulsGameplayAbility::GetPawnCombatComponentFromActorInfo() const
{
	return GetAvatarActorFromActorInfo()->FindComponentByClass<UPawnCombatComponent>();
}

USoulsAbilitySystemComponent* USoulsGameplayAbility::GetSoulsAbilitySystemComponentFromActorInfo() const
{
	return Cast<USoulsAbilitySystemComponent>(CurrentActorInfo->AbilitySystemComponent);
}

FActiveGameplayEffectHandle USoulsGameplayAbility::NativeApplyEffectSpecHandleToTarget(AActor* TargetActor,
	const FGameplayEffectSpecHandle InSpecHandle)
{
	UAbilitySystemComponent* TargetASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(TargetActor);
	check(TargetASC && InSpecHandle.IsValid());
	
	return GetSoulsAbilitySystemComponentFromActorInfo()->ApplyGameplayEffectSpecToTarget(*InSpecHandle.Data, TargetASC);
}

FActiveGameplayEffectHandle USoulsGameplayAbility::BP_ApplyEffectSpecHandleToTarget(AActor* TargetActor,
	const FGameplayEffectSpecHandle InSpecHandle, ESoulsSuccessType& OutSuccessType)
{
	FActiveGameplayEffectHandle ActiveGameplayEffectHandle = NativeApplyEffectSpecHandleToTarget(TargetActor, InSpecHandle);
	OutSuccessType = ActiveGameplayEffectHandle.WasSuccessfullyApplied()? ESoulsSuccessType::Successful : ESoulsSuccessType::Failed;
	return ActiveGameplayEffectHandle;
}
