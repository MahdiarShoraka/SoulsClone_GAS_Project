// Mahdiar Shoraka All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "AnimInstances/SoulsBaseAnimInstance.h"
#include "SoulsCharacterAnimInstance.generated.h"

class ASoulsBaseCharacter;
class UCharacterMovementComponent;
/**
 * 
 */
UCLASS()
class SOULSCLONE_API USoulsCharacterAnimInstance : public USoulsBaseAnimInstance
{
	GENERATED_BODY()
public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds) override;

protected:
	UPROPERTY()	// Used for garbage collection, etc.
	ASoulsBaseCharacter* OwningCharacter;

	UPROPERTY()	
	UCharacterMovementComponent* OwningMovementComponent;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimationData|LocomotionData")
	float GroundSpeed;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimationData|LocomotionData")
	bool bHasAcceleration;
};
