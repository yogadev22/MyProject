// PUBG_VNG -64bit (4.2.0) SDK by BangJO [Z] DM @isar_hackJO To Buy Tool SDK

#include "PUBGM_BangJO.hpp"

namespace SDK
{
//---------------------By BangJO---------------------------
//Functions
//---------------------By BangJO---------------------------

// Function NiagaraAnimNotifies.AnimNotifyState_TimedNiagaraEffect.GetParentCharacter
// (Final, Native, Private, Const)
// Parameters:
// class USkeletalMeshComponent*  MeshComp                       (Parm, ZeroConstructor, InstancedReference, IsPlainOldData)
// class ACharacter*              ReturnValue                    (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)

class ACharacter* UAnimNotifyState_TimedNiagaraEffect::GetParentCharacter(class USkeletalMeshComponent* MeshComp)
{
	static UFunction *pFunc = nullptr;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function NiagaraAnimNotifies.AnimNotifyState_TimedNiagaraEffect.GetParentCharacter");

	UAnimNotifyState_TimedNiagaraEffect_GetParentCharacter_Params params;
	params.MeshComp = MeshComp;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;

	return params.ReturnValue;
}


}

