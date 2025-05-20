// Mahdiar Shoraka All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "AnimInstances/SoulsBaseAnimInstance.h"
#include "SoulsHeroLinkedAnimLayer.generated.h"

class USoulsHeroAnimInstance;
/**
 * 
 */
UCLASS()
class SOULSCLONE_API USoulsHeroLinkedAnimLayer : public USoulsBaseAnimInstance
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, meta = (BlueprintThreadSafe))
	USoulsHeroAnimInstance* GetHeroAnimInstance() const;
};
