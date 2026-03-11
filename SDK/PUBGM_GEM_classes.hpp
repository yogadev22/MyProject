#pragma once

// PUBG_VNG -64bit (4.2.0) SDK by BangJO [Z] DM @isar_hackJO To Buy Tool SDK

namespace SDK
{
//---------------------By BangJO---------------------------
//Classes
//---------------------By BangJO---------------------------

// Class GEM.FpsReportActor
// 0x0000 (0x04B0 - 0x04B0)
class AFpsReportActor : public AActor
{
public:

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = nullptr;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class GEM.FpsReportActor");
		return pStaticClass;
	}

};


}

