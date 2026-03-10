#pragma once

// PUBG_VNG -64bit (4.2.0) SDK by BangJO [Z] DM @isar_hackJO To Buy Tool SDK

namespace SDK
{
//---------------------By BangJO---------------------------
//Classes
//---------------------By BangJO---------------------------

// BlueprintGeneratedClass BP_CustomLayoutProxy.BP_CustomLayoutProxy_C
// 0x0000 (0x01D0 - 0x01D0)
class UBP_CustomLayoutProxy_C : public UCustomLayoutProxy
{
public:

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = nullptr;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("BlueprintGeneratedClass BP_CustomLayoutProxy.BP_CustomLayoutProxy_C");
		return pStaticClass;
	}


	void AddLayoutDetailCache(bool Invalid, struct FBP_STRUCT_UIElemLayoutDetail* BPStruct);
};


}

