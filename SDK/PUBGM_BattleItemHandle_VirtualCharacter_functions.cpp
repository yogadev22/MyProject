// PUBG_VNG -64bit (4.2.0) SDK by BangJO [Z] DM @isar_hackJO To Buy Tool SDK

#include "PUBGM_BangJO.hpp"

namespace SDK
{
//---------------------By BangJO---------------------------
//Functions
//---------------------By BangJO---------------------------

// Function BattleItemHandle_VirtualCharacter.BattleItemHandle_VirtualCharacter_C.ExtractItemData
// (Event, Public, HasOutParms, HasDefaults, BlueprintCallable, BlueprintEvent, Const)
// Parameters:
// struct FBattleItemData         ReturnValue                    (Parm, OutParm, ReturnParm)

struct FBattleItemData UBattleItemHandle_VirtualCharacter_C::ExtractItemData()
{
	static UFunction *pFunc = nullptr;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BattleItemHandle_VirtualCharacter.BattleItemHandle_VirtualCharacter_C.ExtractItemData");

	UBattleItemHandle_VirtualCharacter_C_ExtractItemData_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


}

