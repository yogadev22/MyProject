// Pubg Mobile Battelgrounds By HaMa && SDK_Dumper (4.3.0) SDK by HaMa && SDK_Dumper

#include "../SDK.hpp"

namespace SDK
{
//--------------------------------By HaMa && SDK_Dumper-------------------------------------------
//Functions
//--------------------------------By HaMa && SDK_Dumper-------------------------------------------

// Function BP_CustomLayoutProxy.BP_CustomLayoutProxy_C.AddLayoutDetailCache
// (Public, HasOutParms, HasDefaults, BlueprintCallable, BlueprintEvent)
// Parameters:
// struct FBP_STRUCT_UIElemLayoutDetail BPStruct                       (BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ReferenceParm)
// bool                           Invalid                        (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData)

void UBP_CustomLayoutProxy_C::AddLayoutDetailCache(bool Invalid, struct FBP_STRUCT_UIElemLayoutDetail* BPStruct)
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function BP_CustomLayoutProxy.BP_CustomLayoutProxy_C.AddLayoutDetailCache");

	UBP_CustomLayoutProxy_C_AddLayoutDetailCache_Params params;
	params.Invalid = Invalid;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	if (BPStruct != nullptr)
		*BPStruct = params.BPStruct;
}


}

