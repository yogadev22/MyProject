#pragma once

// Pubg Mobile Battelgrounds By HaMa && SDK_Dumper (4.3.0) SDK by HaMa && SDK_Dumper

namespace SDK
{
//--------------------------------By HaMa && SDK_Dumper-------------------------------------------
//Classes
//--------------------------------By HaMa && SDK_Dumper-------------------------------------------

// Class GEM.FpsReportActor
// 0x0000 (0x04B0 - 0x04B0)
class AFpsReportActor : public AActor
{
public:

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class GEM.FpsReportActor");
		return pStaticClass;
	}

};


}

