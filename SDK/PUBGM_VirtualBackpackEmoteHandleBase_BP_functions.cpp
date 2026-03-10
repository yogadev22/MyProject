// PUBG_VNG -64bit (4.2.0) SDK by BangJO [Z] DM @isar_hackJO To Buy Tool SDK

#include "PUBGM_BangJO.hpp"

namespace SDK
{
//---------------------By BangJO---------------------------
//Functions
//---------------------By BangJO---------------------------

// Function VirtualBackpackEmoteHandleBase_BP.VirtualBackpackEmoteHandleBase_BP_C.ExtractItemData
// (Event, Public, HasOutParms, HasDefaults, BlueprintCallable, BlueprintEvent, Const)
// Parameters:
// struct FBattleItemData         ReturnValue                    (Parm, OutParm, ReturnParm)

struct FBattleItemData UVirtualBackpackEmoteHandleBase_BP_C::ExtractItemData()
{
	static UFunction *pFunc = nullptr;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function VirtualBackpackEmoteHandleBase_BP.VirtualBackpackEmoteHandleBase_BP_C.ExtractItemData");

	UVirtualBackpackEmoteHandleBase_BP_C_ExtractItemData_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


// Function VirtualBackpackEmoteHandleBase_BP.VirtualBackpackEmoteHandleBase_BP_C.HandleDisuse
// (Event, Public, HasOutParms, BlueprintCallable, BlueprintEvent)
// Parameters:
// EBattleItemDisuseReason*       Reason                         (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData)
// bool                           ReturnValue                    (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)

bool UVirtualBackpackEmoteHandleBase_BP_C::HandleDisuse(EBattleItemDisuseReason* Reason)
{
	static UFunction *pFunc = nullptr;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function VirtualBackpackEmoteHandleBase_BP.VirtualBackpackEmoteHandleBase_BP_C.HandleDisuse");

	UVirtualBackpackEmoteHandleBase_BP_C_HandleDisuse_Params params;
	params.Reason = Reason;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


// Function VirtualBackpackEmoteHandleBase_BP.VirtualBackpackEmoteHandleBase_BP_C.HandleUse
// (Event, Public, HasOutParms, BlueprintCallable, BlueprintEvent)
// Parameters:
// struct FBattleItemUseTarget*   Target                         (BlueprintVisible, BlueprintReadOnly, Parm)
// EBattleItemUseReason*          Reason                         (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData)
// bool                           ReturnValue                    (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)

bool UVirtualBackpackEmoteHandleBase_BP_C::HandleUse(struct FBattleItemUseTarget* Target, EBattleItemUseReason* Reason)
{
	static UFunction *pFunc = nullptr;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function VirtualBackpackEmoteHandleBase_BP.VirtualBackpackEmoteHandleBase_BP_C.HandleUse");

	UVirtualBackpackEmoteHandleBase_BP_C_HandleUse_Params params;
	params.Target = Target;
	params.Reason = Reason;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


// Function VirtualBackpackEmoteHandleBase_BP.VirtualBackpackEmoteHandleBase_BP_C.HandlePickup
// (Event, Public, HasOutParms, BlueprintCallable, BlueprintEvent)
// Parameters:
// TScriptInterface<class UItemContainerInterface> ItemContainer                  (BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ZeroConstructor, ReferenceParm, IsPlainOldData)
// struct FBattleItemPickupInfo*  PickupInfo                     (BlueprintVisible, BlueprintReadOnly, Parm)
// EBattleItemPickupReason*       Reason                         (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData)
// bool                           ReturnValue                    (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)

bool UVirtualBackpackEmoteHandleBase_BP_C::HandlePickup(struct FBattleItemPickupInfo* PickupInfo, EBattleItemPickupReason* Reason, TScriptInterface<class UItemContainerInterface>* ItemContainer)
{
	static UFunction *pFunc = nullptr;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function VirtualBackpackEmoteHandleBase_BP.VirtualBackpackEmoteHandleBase_BP_C.HandlePickup");

	UVirtualBackpackEmoteHandleBase_BP_C_HandlePickup_Params params;
	params.PickupInfo = PickupInfo;
	params.Reason = Reason;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	if (ItemContainer != nullptr)
		*ItemContainer = params.ItemContainer;

	return params.ReturnValue;
}


}

