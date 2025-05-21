// Mahdiar Shoraka All Rights Reserved


#include "SoulsFunctionLibrary.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystem/SoulsAbilitySystemComponent.h"

USoulsAbilitySystemComponent* USoulsFunctionLibrary::NativeGetSoulsASCFromActor(AActor* InActor)
{
	check(InActor);
	return CastChecked<USoulsAbilitySystemComponent>(UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(InActor));
}

void USoulsFunctionLibrary::AddGameplayTagToActorIfNone(AActor* InActor, FGameplayTag TagToAdd)
{
	USoulsAbilitySystemComponent* ASC = NativeGetSoulsASCFromActor(InActor);
	if (!ASC->HasMatchingGameplayTag(TagToAdd))
	{
		ASC->AddLooseGameplayTag(TagToAdd);
	}
}

void USoulsFunctionLibrary::RemoveGameplayTagFromActorIfFound(AActor* InActor, FGameplayTag TagToRemove)
{
	USoulsAbilitySystemComponent* ASC = NativeGetSoulsASCFromActor(InActor);
	if (ASC->HasMatchingGameplayTag(TagToRemove))
	{
		ASC->RemoveLooseGameplayTag(TagToRemove);
	}
}

bool USoulsFunctionLibrary::NativeDoesActorHaveGameplayTag(AActor* InActor, FGameplayTag TagToCheck)
{
	USoulsAbilitySystemComponent* ASC = NativeGetSoulsASCFromActor(InActor);
	return ASC->HasMatchingGameplayTag(TagToCheck);
}

void USoulsFunctionLibrary::BP_DoesActorHaveGameplayTag(AActor* InActor, FGameplayTag TagToCheck,
	ESoulsConfirmType& OutConfirmType)
{
	OutConfirmType = NativeDoesActorHaveGameplayTag(InActor, TagToCheck) ? ESoulsConfirmType::Yes : ESoulsConfirmType::No;
}
