#pragma once

// PUBG_VNG -64bit (4.2.0) SDK by BangJO [Z] DM @isar_hackJO To Buy Tool SDK

namespace SDK
{
//---------------------By BangJO---------------------------
//Classes
//---------------------By BangJO---------------------------

// BlueprintGeneratedClass GameLogicManagerBase.GameLogicManagerBase_C
// 0x0000 (0x0180 - 0x0180)
class UGameLogicManagerBase_C : public UGameBusinessManager
{
public:

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = nullptr;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("BlueprintGeneratedClass GameLogicManagerBase.GameLogicManagerBase_C");
		return pStaticClass;
	}

};


}

