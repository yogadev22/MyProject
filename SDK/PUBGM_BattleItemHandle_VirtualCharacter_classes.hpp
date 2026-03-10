#pragma once

// PUBG_VNG -64bit (4.2.0) SDK by BangJO [Z] DM @isar_hackJO To Buy Tool SDK

namespace SDK
{
//---------------------By BangJO---------------------------
//Classes
//---------------------By BangJO---------------------------

// BlueprintGeneratedClass BattleItemHandle_VirtualCharacter.BattleItemHandle_VirtualCharacter_C
// 0x0000 (0x0138 - 0x0138)
class UBattleItemHandle_VirtualCharacter_C : public UBattleItemHandle_VirtualItem_C
{
public:

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = nullptr;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("BlueprintGeneratedClass BattleItemHandle_VirtualCharacter.BattleItemHandle_VirtualCharacter_C");
		return pStaticClass;
	}


	struct FBattleItemData ExtractItemData();
};


}

