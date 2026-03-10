#pragma once

// PUBG_VNG -64bit (4.2.0) SDK by BangJO [Z] DM @isar_hackJO To Buy Tool SDK

#include "PUBGM_BangJO.hpp"

namespace SDK
{
//---------------------By BangJO---------------------------
//Parameters
//---------------------By BangJO---------------------------

// Function ActorSequence.ActorSequenceComponent.StopPlay
struct UActorSequenceComponent_StopPlay_Params
{
};

// Function ActorSequence.ActorSequenceComponent.StartPlay
struct UActorSequenceComponent_StartPlay_Params
{
	float                                              StartTime;                                                // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function ActorSequence.ActorSequenceComponent.OnStopOrFinsh
struct UActorSequenceComponent_OnStopOrFinsh_Params
{
};

// Function ActorSequence.ActorSequenceComponent.GetLength
struct UActorSequenceComponent_GetLength_Params
{
	float                                              ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

}

