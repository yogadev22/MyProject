#pragma once

// PUBG_VNG -64bit (4.2.0) SDK by BangJO [Z] DM @isar_hackJO To Buy Tool SDK

namespace SDK
{
//---------------------By BangJO---------------------------
//Classes
//---------------------By BangJO---------------------------

// Class ClusterReplication.ClusterReplicationSubsystem
// 0x0590 (0x05B8 - 0x0028)
class UClusterReplicationSubsystem : public UObject
{
public:
	unsigned char                                      UnknownData00[0x590];                                     // 0x0028(0x0590) MISSED OFFSET

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = nullptr;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class ClusterReplication.ClusterReplicationSubsystem");
		return pStaticClass;
	}


	void SetAutoClearCache(bool Val);
	void SetAutoCache(bool Val);
	void RemoveAllCachedObjectData();
};


// Class ClusterReplication.ClusterEntityInterface
// 0x0000 (0x0028 - 0x0028)
class UClusterEntityInterface : public UInterface
{
public:

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = nullptr;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class ClusterReplication.ClusterEntityInterface");
		return pStaticClass;
	}

};


}

