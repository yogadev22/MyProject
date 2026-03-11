#pragma once

// Pubg Mobile Battelgrounds By HaMa && SDK_Dumper (4.3.0) SDK by HaMa && SDK_Dumper

#include "../SDK.hpp"

namespace SDK
{
//--------------------------------By HaMa && SDK_Dumper-------------------------------------------
//Parameters
//--------------------------------By HaMa && SDK_Dumper-------------------------------------------

// Function UITweens.TweenManager.TweenScale
struct UTweenManager_TweenScale_Params
{
	class UWidget*                                     Widget;                                                   // (Parm, ZeroConstructor, InstancedReference, IsPlainOldData)
	struct FVector2D                                   From;                                                     // (Parm, IsPlainOldData)
	struct FVector2D                                   To;                                                       // (Parm, IsPlainOldData)
	float                                              Timespan;                                                 // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                Type;                                                     // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function UITweens.TweenManager.TweenPosition
struct UTweenManager_TweenPosition_Params
{
	class UWidget*                                     Widget;                                                   // (Parm, ZeroConstructor, InstancedReference, IsPlainOldData)
	struct FVector2D                                   From;                                                     // (Parm, IsPlainOldData)
	struct FVector2D                                   To;                                                       // (Parm, IsPlainOldData)
	float                                              Timespan;                                                 // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                Type;                                                     // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function UITweens.TweenManager.TweenAlpha
struct UTweenManager_TweenAlpha_Params
{
	class UWidget*                                     Widget;                                                   // (Parm, ZeroConstructor, InstancedReference, IsPlainOldData)
	float                                              From;                                                     // (Parm, ZeroConstructor, IsPlainOldData)
	float                                              To;                                                       // (Parm, ZeroConstructor, IsPlainOldData)
	float                                              Timespan;                                                 // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                Type;                                                     // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function UITweens.TweenManager.Tick
struct UTweenManager_Tick_Params
{
	float                                              DeltaTime;                                                // (Parm, ZeroConstructor, IsPlainOldData)
};

}

