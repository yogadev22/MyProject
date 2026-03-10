#pragma once

// PUBG_VNG -64bit (4.2.0) SDK by BangJO [Z] DM @isar_hackJO To Buy Tool SDK

namespace SDK
{
//---------------------By BangJO---------------------------
//Classes
//---------------------By BangJO---------------------------

// Class PixUICanvas.PxCanvasObj
// 0x0000 (0x0028 - 0x0028)
class UPxCanvasObj : public UObject
{
public:

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = nullptr;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class PixUICanvas.PxCanvasObj");
		return pStaticClass;
	}

};


}

