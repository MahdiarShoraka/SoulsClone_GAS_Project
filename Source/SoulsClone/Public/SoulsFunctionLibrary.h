// Mahdiar Shoraka All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "SoulsTypes/SoulsEnumTypes.h"
#include "SoulsFunctionLibrary.generated.h"

class UPawnCombatComponent;
class USoulsAbilitySystemComponent;

/**
 * 
 */
UCLASS()
class SOULSCLONE_API USoulsFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	static USoulsAbilitySystemComponent* NativeGetSoulsASCFromActor(AActor* InActor);

	UFUNCTION(BlueprintCallable, Category = "Souls|FunctionLibrary")
	static void AddGameplayTagToActorIfNone(AActor* InActor, FGameplayTag TagToAdd);

	UFUNCTION(BlueprintCallable, Category = "Souls|FunctionLibrary")
	static void RemoveGameplayTagFromActorIfFound(AActor* InActor, FGameplayTag TagToRemove);

	static bool NativeDoesActorHaveGameplayTag(AActor* InActor, FGameplayTag TagToCheck);

	UFUNCTION(BlueprintCallable, Category = "Souls|FunctionLibrary", meta = (DisplayName = "Does Actor Have Gameplay Tag", ExpandEnumAsExecs = "OutConfirmType"))
	static void BP_DoesActorHaveGameplayTag(AActor* InActor, FGameplayTag TagToCheck, ESoulsConfirmType& OutConfirmType);

	static UPawnCombatComponent* NativeGetPawnCombatComponentFromActor(AActor* InActor);

	UFUNCTION(BlueprintCallable, Category = "Souls|FunctionLibrary", meta = (DisplayName = "Get Pawn Combat Component From Actor", ExpandEnumAsExecs = "OutValidType"))
	static UPawnCombatComponent* BP_GetPawnCombatComponentFromActor(AActor* InActor, ESoulsValidType& OutValidType);
	
};
