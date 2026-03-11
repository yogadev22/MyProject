#pragma once

// Pubg Mobile Battelgrounds By HaMa && SDK_Dumper (4.3.0) SDK by HaMa && SDK_Dumper

namespace SDK
{
//--------------------------------By HaMa && SDK_Dumper-------------------------------------------
//Enums
//--------------------------------By HaMa && SDK_Dumper-------------------------------------------

// Enum CommonLib.DownloadResult
enum class EDownloadResult : uint8_t
{
	SuccessDownloading             = 0,
	DownloadFailed                 = 1,
	SaveFailed                     = 2,
	DirectoryCreationFailed        = 3,
	DownloadResult_MAX             = 4
};



//--------------------------------By HaMa && SDK_Dumper-------------------------------------------
//Script Structs
//--------------------------------By HaMa && SDK_Dumper-------------------------------------------

// ScriptStruct CommonLib.ServiceCollection
// 0x0050
struct FServiceCollection
{
	TMap<struct FString, class UObject*>               ServiceMap;                                               // 0x0000(0x0050) (ZeroConstructor)
};

}

