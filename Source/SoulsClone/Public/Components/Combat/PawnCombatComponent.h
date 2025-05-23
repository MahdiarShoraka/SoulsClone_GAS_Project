// Mahdiar Shoraka All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Components/PawnExtensionComponentBase.h"
#include "PawnCombatComponent.generated.h"

class ASoulsWeaponBase;

UENUM(BlueprintType)
enum class EToggleDamageType : uint8
{
	CurrentEquippedWeapon,
	LeftHand,
	RightHand,
};

/**
 * 
 */
UCLASS()
class SOULSCLONE_API UPawnCombatComponent : public UPawnExtensionComponentBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Combat")
	void RegisterSpawnedWeapon(FGameplayTag InWeaponTagToRegister, ASoulsWeaponBase* InWeaponToRegister, bool bRegisterAsEquippedWeapon = false);

	UFUNCTION(BlueprintCallable, Category = "Combat")
	ASoulsWeaponBase* GetCharacterCarriedWeaponByTag(FGameplayTag InWeaponTagToGet) const;

	UPROPERTY(BlueprintReadWrite, Category = "Combat")
	FGameplayTag CurrentEquippedWeaponTag;

	UFUNCTION(BlueprintCallable, Category = "Combat")
	ASoulsWeaponBase* GetCharacterCurrentEquippedWeapon() const;

	UFUNCTION(BlueprintCallable, Category = "Combat")
	void ToggleWeaponCollision(bool bShouldEnable, EToggleDamageType ToggleDamageType = EToggleDamageType::CurrentEquippedWeapon);

	virtual void OnHitTargetActor(AActor* HitActor);
	virtual void OnWeaponPulledFromTargetActor(AActor* InteractedActor);

protected:
	TArray<AActor*> OverlappedActors;	

private:
	TMap<FGameplayTag, ASoulsWeaponBase*> CharacterCarriedWeaponMap;
};
