// Mahdiar Shoraka All Rights Reserved

#pragma once

#include "NativeGameplayTags.h"

namespace SoulsGameplayTags
{
	/** Input Tags **/
	SOULSCLONE_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Move);
	SOULSCLONE_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Look);
	SOULSCLONE_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_EquipAxe);
	SOULSCLONE_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_UnequipAxe);
	
	/** Player tags **/
	SOULSCLONE_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Weapon_Axe);

	SOULSCLONE_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Event_Equip_Axe);
	SOULSCLONE_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Event_Unequip_Axe);
}
