// Mahdiar Shoraka All Rights Reserved


#include "AnimInstances/Hero/SoulsHeroLinkedAnimLayer.h"

#include "AnimInstances/Hero/SoulsHeroAnimInstance.h"

USoulsHeroAnimInstance* USoulsHeroLinkedAnimLayer::GetHeroAnimInstance() const
{
	return Cast<USoulsHeroAnimInstance>(GetOwningComponent()->GetAnimInstance());
}
