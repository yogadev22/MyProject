#pragma once

// PUBG_VNG -64bit (4.2.0) SDK by BangJO [Z] DM @isar_hackJO To Buy Tool SDK

namespace SDK
{
//---------------------By BangJO---------------------------
//Classes
//---------------------By BangJO---------------------------

// Class SurviveLoadingScreen.SurviveLoadingSettings
// 0x0020 (0x0058 - 0x0038)
class USurviveLoadingSettings : public UDeveloperSettings
{
public:
	TArray<struct FSoftObjectPath>                     Images;                                                   // 0x0038(0x0010) (Edit, ZeroConstructor, Config)
	TArray<struct FSoftObjectPath>                     Videos;                                                   // 0x0048(0x0010) (Edit, ZeroConstructor, Config)

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = nullptr;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class SurviveLoadingScreen.SurviveLoadingSettings");
		return pStaticClass;
	}

};


}

