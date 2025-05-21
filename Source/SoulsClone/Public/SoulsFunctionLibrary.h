// Mahdiar Shoraka All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "SoulsFunctionLibrary.generated.h"

class USoulsAbilitySystemComponent;

UENUM()
enum class ESoulsConfirmType : uint8
{
	Yes,
	No
};

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
};
