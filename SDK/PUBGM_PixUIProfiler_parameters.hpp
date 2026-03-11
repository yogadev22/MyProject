#pragma once

// Pubg Mobile Battelgrounds By HaMa && SDK_Dumper (4.3.0) SDK by HaMa && SDK_Dumper

#include "../SDK.hpp"

namespace SDK
{
//--------------------------------By HaMa && SDK_Dumper-------------------------------------------
//Parameters
//--------------------------------By HaMa && SDK_Dumper-------------------------------------------

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

