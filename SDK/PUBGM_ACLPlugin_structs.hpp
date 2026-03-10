#pragma once

// PUBG_VNG -64bit (4.2.0) SDK by BangJO [Z] DM @isar_hackJO To Buy Tool SDK

namespace SDK
{
//---------------------By BangJO---------------------------
//Enums
//---------------------By BangJO---------------------------

// Enum ACLPlugin.ACLCompressionLevel
enum class EACLCompressionLevel : uint8_t
{
	ACLCL_Lowest                   = 0,
	ACLCL_Low                      = 1,
	ACLCL_Medium                   = 2,
	ACLCL_High                     = 3,
	ACLCL_Highest                  = 4,
	ACLCL_MAX                      = 5
};


// Enum ACLPlugin.ACLVectorFormat
enum class EACLVectorFormat : uint8_t
{
	ACLVF_Vector3                  = 0,
	ACLVF_Vector3_Variable         = 1,
	ACLVF_Vector3_MAX              = 2
};


// Enum ACLPlugin.ACLRotationFormat
enum class EACLRotationFormat : uint8_t
{
	ACLRF_Quat                     = 0,
	ACLRF_QuatDropW                = 1,
	ACLRF_QuatDropW_Variable       = 2,
	ACLRF_MAX                      = 3
};



}

