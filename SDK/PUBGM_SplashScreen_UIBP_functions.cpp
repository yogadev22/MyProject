// PUBG_VNG -64bit (4.2.0) SDK by BangJO [Z] DM @isar_hackJO To Buy Tool SDK

#include "PUBGM_BangJO.hpp"

namespace SDK
{
//---------------------By BangJO---------------------------
//Functions
//---------------------By BangJO---------------------------

// Function SplashScreen_UIBP.SplashScreen_UIBP_C.Construct
// (BlueprintCosmetic, Event, Public, BlueprintEvent)

void USplashScreen_UIBP_C::Construct()
{
	static UFunction *pFunc = nullptr;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function SplashScreen_UIBP.SplashScreen_UIBP_C.Construct");

	USplashScreen_UIBP_C_Construct_Params params;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


// Function SplashScreen_UIBP.SplashScreen_UIBP_C.ExecuteUbergraph_SplashScreen_UIBP
// ()
// Parameters:
// int                            EntryPoint                     (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData)

void USplashScreen_UIBP_C::ExecuteUbergraph_SplashScreen_UIBP(int EntryPoint)
{
	static UFunction *pFunc = nullptr;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function SplashScreen_UIBP.SplashScreen_UIBP_C.ExecuteUbergraph_SplashScreen_UIBP");

	USplashScreen_UIBP_C_ExecuteUbergraph_SplashScreen_UIBP_Params params;
	params.EntryPoint = EntryPoint;

	auto flags = pFunc->FunctionFlags;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


}

