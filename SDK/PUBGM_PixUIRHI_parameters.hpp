#pragma once

// PUBG_VNG -64bit (4.2.0) SDK by BangJO [Z] DM @isar_hackJO To Buy Tool SDK

#include "PUBGM_BangJO.hpp"

namespace SDK
{
//---------------------By BangJO---------------------------
//Parameters
//---------------------By BangJO---------------------------

// Function PixUIRHI.PxRHIImage.GetHandleObject
struct UPxRHIImage_GetHandleObject_Params
{
	class UObject*                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function PixUIRHI.PxRHIMgr.RHIImageUpdate
struct UPxRHIMgr_RHIImageUpdate_Params
{
	class UPxRHIMgr*                                   pPxRHIImage;                                              // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function PixUIRHI.PxRHIMgr.RHIImageFindByObject
struct UPxRHIMgr_RHIImageFindByObject_Params
{
	class UObject*                                     pCoreObject;                                              // (Parm, ZeroConstructor, IsPlainOldData)
	class UPxRHIMgr*                                   ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function PixUIRHI.PxRHIMgr.RHIImageDestroy
struct UPxRHIMgr_RHIImageDestroy_Params
{
	class UPxRHIMgr*                                   pPxRHIImage;                                              // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function PixUIRHI.PxRHIMgr.RHIImageCreate
struct UPxRHIMgr_RHIImageCreate_Params
{
	class UPxRHIImage*                                 ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function PixUIRHI.PxRHIMgr.Get
struct UPxRHIMgr_Get_Params
{
	class UPxRHIMgr*                                   ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

}

