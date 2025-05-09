// Mahdiar Shoraka All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "AnimInstances/SoulsCharacterAnimInstance.h"
#include "SoulsHeroAnimInstance.generated.h"

class ASoulsHeroCharacter;
/**
 * 
 */
UCLASS()
class SOULSCLONE_API USoulsHeroAnimInstance : public USoulsCharacterAnimInstance
{
	GENERATED_BODY()

public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds) override;

protected:
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimationData|References")
	ASoulsHeroCharacter* OwningHeroCharacter;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimationData|References")
	bool bShouldEnterRelaxState;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "AnimationData|References")
	float EnterRelaxStateThreshold = 5.f;

	float IdleElapsedTime = 0.f;
};
