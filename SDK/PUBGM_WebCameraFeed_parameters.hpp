#pragma once

// Pubg Mobile Battelgrounds By HaMa && SDK_Dumper (4.3.0) SDK by HaMa && SDK_Dumper

#include "../SDK.hpp"

namespace SDK
{
//--------------------------------By HaMa && SDK_Dumper-------------------------------------------
//Parameters
//--------------------------------By HaMa && SDK_Dumper-------------------------------------------

// Function WebCameraFeed.WebCameraWidget.UnLockScreenOrientation
struct UWebCameraWidget_UnLockScreenOrientation_Params
{
};

// Function WebCameraFeed.WebCameraWidget.SwitchFrontAndBackCamera
struct UWebCameraWidget_SwitchFrontAndBackCamera_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function WebCameraFeed.WebCameraWidget.SetDeviceId
struct UWebCameraWidget_SetDeviceId_Params
{
	int                                                ID;                                                       // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function WebCameraFeed.WebCameraWidget.SetColorAndOpacity
struct UWebCameraWidget_SetColorAndOpacity_Params
{
	struct FLinearColor                                InColorAndOpacity;                                        // (Parm, IsPlainOldData)
};

// Function WebCameraFeed.WebCameraWidget.SaveAsImage
struct UWebCameraWidget_SaveAsImage_Params
{
	struct FString                                     Filename;                                                 // (Parm, ZeroConstructor)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function WebCameraFeed.WebCameraWidget.ReleaseVideoGrabber
struct UWebCameraWidget_ReleaseVideoGrabber_Params
{
};

// Function WebCameraFeed.WebCameraWidget.LockScreenOrientation
struct UWebCameraWidget_LockScreenOrientation_Params
{
};

// Function WebCameraFeed.WebCameraWidget.InitVideoGrabber
struct UWebCameraWidget_InitVideoGrabber_Params
{
};

// Function WebCameraFeed.WebCameraWidget.GetFrontCameraId
struct UWebCameraWidget_GetFrontCameraId_Params
{
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function WebCameraFeed.WebCameraWidget.GetBackCameraId
struct UWebCameraWidget_GetBackCameraId_Params
{
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

}

