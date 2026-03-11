#pragma once

// PUBG_VNG -64bit (4.2.0) SDK by BangJO [Z] DM @isar_hackJO To Buy Tool SDK

#include "PUBGM_BangJO.hpp"

namespace SDK
{
//---------------------By BangJO---------------------------
//Parameters
//---------------------By BangJO---------------------------

// Function QRCodeUtility.VideoThumbnailGenerator.GenerateVideoThumbnailAsync
struct UVideoThumbnailGenerator_GenerateVideoThumbnailAsync_Params
{
	struct FString                                     videoPath;                                                // (Parm, ZeroConstructor)
	int                                                thumbnailSize;                                            // (Parm, ZeroConstructor, IsPlainOldData)
	struct FScriptDelegate                             OnThumbnailGenerated;                                     // (ConstParm, Parm, OutParm, ZeroConstructor, ReferenceParm)
};

// Function QRCodeUtility.ZXingScanner.Encode
struct UZXingScanner_Encode_Params
{
	struct FString                                     Text;                                                     // (Parm, ZeroConstructor)
	class UTexture2D*                                  ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function QRCodeUtility.ZXingScanner.Decode
struct UZXingScanner_Decode_Params
{
	class UTexture2D*                                  Texture;                                                  // (Parm, ZeroConstructor, IsPlainOldData)
	struct FZXingScanResult                            OutResult;                                                // (Parm, OutParm)
	struct FVector4                                    InRect;                                                   // (ConstParm, Parm, OutParm, ReferenceParm, IsPlainOldData)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

}

