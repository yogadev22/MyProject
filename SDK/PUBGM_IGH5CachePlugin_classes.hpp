#pragma once

// Pubg Mobile Battelgrounds By HaMa && SDK_Dumper (4.3.0) SDK by HaMa && SDK_Dumper

namespace SDK
{
//--------------------------------By HaMa && SDK_Dumper-------------------------------------------
//Classes
//--------------------------------By HaMa && SDK_Dumper-------------------------------------------

// Class IGH5CachePlugin.IGH5CachePluginSettings
// 0x0010 (0x0038 - 0x0028)
class UIGH5CachePluginSettings : public UObject
{
public:
	struct FString                                     Html5Url;                                                 // 0x0028(0x0010) (Edit, ZeroConstructor, Config)

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class IGH5CachePlugin.IGH5CachePluginSettings");
		return pStaticClass;
	}

};


}

