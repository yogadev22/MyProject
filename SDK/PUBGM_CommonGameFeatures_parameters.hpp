#pragma once

// Pubg Mobile Battelgrounds By HaMa && SDK_Dumper (4.3.0) SDK by HaMa && SDK_Dumper

#include "../SDK.hpp"

namespace SDK
{
//--------------------------------By HaMa && SDK_Dumper-------------------------------------------
//Parameters
//--------------------------------By HaMa && SDK_Dumper-------------------------------------------

// Function CommonGameFeatures.ActorRepControlComponent.ToggleGroupedRepControlByUID
struct UActorRepControlComponent_ToggleGroupedRepControlByUID_Params
{
	int64_t                                            UID;                                                      // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                ControlMark;                                              // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                RepControlGroup;                                          // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function CommonGameFeatures.ActorRepControlComponent.ShouldBlockRepByUID
struct UActorRepControlComponent_ShouldBlockRepByUID_Params
{
	int64_t                                            UID;                                                      // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                RepControlGroup;                                          // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function CommonGameFeatures.ActorRepControlComponent.GetControlGroupData
struct UActorRepControlComponent_GetControlGroupData_Params
{
	int                                                RepControlGroup;                                          // (Parm, ZeroConstructor, IsPlainOldData)
	struct FRepControlGroupData                        OutData;                                                  // (Parm, OutParm)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function CommonGameFeatures.RepControlActorBase.IsNetRelevantForCustomCheck
struct ARepControlActorBase_IsNetRelevantForCustomCheck_Params
{
	class AActor*                                      RealViewer;                                               // (ConstParm, Parm, ZeroConstructor, IsPlainOldData)
	class AActor*                                      ViewTarget;                                               // (ConstParm, Parm, ZeroConstructor, IsPlainOldData)
	struct FVector                                     SrcLocation;                                              // (ConstParm, Parm, OutParm, ReferenceParm, IsPlainOldData)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

}

