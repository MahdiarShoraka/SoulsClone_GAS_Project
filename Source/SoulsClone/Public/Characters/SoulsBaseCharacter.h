// Mahdiar Shoraka All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "SoulsBaseCharacter.generated.h"

// Forward Declarations
class USoulsAbilitySystemComponent;
class USoulsAttributeSet;

UCLASS()
class SOULSCLONE_API ASoulsBaseCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASoulsBaseCharacter();

	//~ Begin IAbilitySystemInterface Interface
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	//~ End IAbilitySystemInterface Interface

protected:
	//~ Begin APawn Interface
	virtual void PossessedBy(AController* NewController) override;
	//~ End APawn Interface
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="AbilitySystem")
	USoulsAbilitySystemComponent* SoulsAbilitySystemComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="AbilitySystem")
	USoulsAttributeSet* SoulsAttributeSet;

public:
	FORCEINLINE USoulsAbilitySystemComponent* GetSoulsAbilitySystemComponent() const { return SoulsAbilitySystemComponent; }
	FORCEINLINE USoulsAttributeSet* GetSoulsAttribute() const { return SoulsAttributeSet; }
};