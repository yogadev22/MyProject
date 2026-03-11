#pragma once

// PUBG_VNG -64bit (4.2.0) SDK by BangJO [Z] DM @isar_hackJO To Buy Tool SDK

#include "PUBGM_BangJO.hpp"

namespace SDK
{
//---------------------By BangJO---------------------------
//Parameters
//---------------------By BangJO---------------------------

// Function Intl.StatManager.ReportUAStatsEvent
struct UStatManager_ReportUAStatsEvent_Params
{
	TArray<struct FString>                             InReportChannels;                                         // (ConstParm, Parm, OutParm, ZeroConstructor, ReferenceParm)
	struct FString                                     InEventName;                                              // (Parm, ZeroConstructor)
	TMap<struct FString, struct FString>               InParams;                                                 // (ConstParm, Parm, OutParm, ZeroConstructor, ReferenceParm)
	bool                                               InIsRealTime;                                             // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Intl.StatManager.ReportRevenue
struct UStatManager_ReportRevenue_Params
{
	int                                                InPurchaseEventType;                                      // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     InCurrencyCode;                                           // (Parm, ZeroConstructor)
	struct FString                                     InExpense;                                                // (Parm, ZeroConstructor)
	TMap<struct FString, struct FString>               InParams;                                                 // (ConstParm, Parm, OutParm, ZeroConstructor, ReferenceParm)
	struct FString                                     InExtraJson;                                              // (Parm, ZeroConstructor)
};

// Function Intl.StatManager.ReportPurchase
struct UStatManager_ReportPurchase_Params
{
	int                                                InPurchaseEventType;                                      // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     InCurrencyCode;                                           // (Parm, ZeroConstructor)
	struct FString                                     InExpense;                                                // (Parm, ZeroConstructor)
	bool                                               isRealTime;                                               // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Intl.StatManager.ReportEventWithString
struct UStatManager_ReportEventWithString_Params
{
	int                                                EventType;                                                // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     _eventBody;                                               // (Parm, ZeroConstructor)
	bool                                               isRealTime;                                               // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Intl.StatManager.ReportEventWithParam
struct UStatManager_ReportEventWithParam_Params
{
	int                                                EventType;                                                // (Parm, ZeroConstructor, IsPlainOldData)
	TMap<struct FString, struct FString>               _params;                                                  // (Parm, ZeroConstructor)
	bool                                               isRealTime;                                               // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Intl.StatManager.ReportEventWithNoParam
struct UStatManager_ReportEventWithNoParam_Params
{
	int                                                EventType;                                                // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               isRealTime;                                               // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Intl.StatManager.GetInstance
struct UStatManager_GetInstance_Params
{
	class UStatManager*                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

}

