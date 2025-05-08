// Mahdiar Shoraka All Rights Reserved


#include "AnimInstances/SoulsCharacterAnimInstance.h"
#include "Characters/SoulsBaseCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

void USoulsCharacterAnimInstance::NativeInitializeAnimation()
{
	// do not need Super as it is empty
	OwningCharacter = Cast<ASoulsBaseCharacter>(TryGetPawnOwner());
	if (OwningCharacter)
	{
		OwningMovementComponent = OwningCharacter->GetCharacterMovement();
	}
}

void USoulsCharacterAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	// do not need Super as it is empty
	if (!OwningCharacter || !OwningMovementComponent) return;

	GroundSpeed = OwningCharacter->GetVelocity().Size2D();
	bHasAcceleration = OwningMovementComponent->GetCurrentAcceleration().SizeSquared2D() > 0.f;
}
