#pragma once

// PUBG_VNG -64bit (4.2.0) SDK by BangJO [Z] DM @isar_hackJO To Buy Tool SDK

#include "PUBGM_BangJO.hpp"

namespace SDK
{
//---------------------By BangJO---------------------------
//Parameters
//---------------------By BangJO---------------------------

// Function PixUIProfiler.PxProfilerMgr.StartProfiler
struct UPxProfilerMgr_StartProfiler_Params
{
};

// Function PixUIProfiler.PxProfilerMgr.PxProfilerCapabilitySwitch
struct UPxProfilerMgr_PxProfilerCapabilitySwitch_Params
{
	EPxProfilerCapability                              EPxProfilerCapability;                                    // (ConstParm, Parm, ZeroConstructor, IsPlainOldData)
	bool                                               bOpen;                                                    // (ConstParm, Parm, ZeroConstructor, IsPlainOldData)
};

// Function PixUIProfiler.PxProfilerMgr.Print
struct UPxProfilerMgr_Print_Params
{
};

// Function PixUIProfiler.PxProfilerMgr.GetPxProfilerCapability
struct UPxProfilerMgr_GetPxProfilerCapability_Params
{
	EPxProfilerCapability                              EPxProfilerCapability;                                    // (ConstParm, Parm, ZeroConstructor, IsPlainOldData)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function PixUIProfiler.PxProfilerMgr.EndProfiler
struct UPxProfilerMgr_EndProfiler_Params
{
};

// Function PixUIProfiler.PxProfilerMgr.Check
struct UPxProfilerMgr_Check_Params
{
};

}

