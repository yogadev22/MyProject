// PUBG_VNG -64bit (4.2.0) SDK by BangJO [Z] DM @isar_hackJO To Buy Tool SDK

#include "PUBGM_BangJO.hpp"

namespace SDK
{
//---------------------By BangJO---------------------------
//Functions
//---------------------By BangJO---------------------------

// Function GeneralNode.GNSharedDelegate.EventTrigger
// (Final, Native, Public, BlueprintCallable)

void UGNSharedDelegate::EventTrigger()
{
	static UFunction *pFunc = nullptr;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function GeneralNode.GNSharedDelegate.EventTrigger");

	UGNSharedDelegate_EventTrigger_Params params;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


}

