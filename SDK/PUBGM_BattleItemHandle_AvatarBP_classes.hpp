#pragma once

// PUBG_VNG -64bit (4.2.0) SDK by BangJO [Z] DM @isar_hackJO To Buy Tool SDK

namespace SDK
{
//---------------------By BangJO---------------------------
//Classes
//---------------------By BangJO---------------------------

// BlueprintGeneratedClass BattleItemHandle_AvatarBP.BattleItemHandle_AvatarBP_C
// 0x0092 (0x0B82 - 0x0AF0)
class UBattleItemHandle_AvatarBP_C : public UBackpackAvatarHandle
{
public:
	class ASTExtraPlayerController*                    OwningPlayerController;                                   // 0x0AF0(0x0008) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnTemplate, IsPlainOldData)
	class ASTExtraBaseCharacter*                       OwningCharacter;                                          // 0x0AF8(0x0008) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnTemplate, DisableEditOnInstance, IsPlainOldData)
	class UBackpackComponent*                          OwningBackpackComponent;                                  // 0x0B00(0x0008) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x8];                                       // 0x0B08(0x0008) MISSED OFFSET
	struct FTransform                                  SourceWrapperTrans;                                       // 0x0B10(0x0030) (Edit, BlueprintVisible, DisableEditOnInstance, IsPlainOldData)
	struct FTransform                                  WrapperPutdownTrans;                                      // 0x0B40(0x0030) (Edit, BlueprintVisible, DisableEditOnInstance, IsPlainOldData)
	class UClass*                                      WrapperClass;                                             // 0x0B70(0x0008) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class UBattleItemHandleBase*                       CharacterItemHandle;                                      // 0x0B78(0x0008) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TEnumAsByte<enum EnumAvatarSlotNameConfig>         SlotNameConfig;                                           // 0x0B80(0x0001) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TEnumAsByte<enum EnumAvatarForceGender>            ForceGender;                                              // 0x0B81(0x0001) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = nullptr;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("BlueprintGeneratedClass BattleItemHandle_AvatarBP.BattleItemHandle_AvatarBP_C");
		return pStaticClass;
	}


	bool IsSwimConfig();
	bool BPNeedCheckCapacityInHandleDisuse(EBattleItemDisuseReason* Reason);
	void GetWrapperClass(class UClass** WrapperClass);
	struct FBattleItemData ExtractItemData();
	void LocalHandleDisuse();
	class UWorld* GetWorldInternal();
	void SpawnWrapperOnGround(class UClass* WrapperClass, bool bUseRandomLoc);
	bool HandleDisuse(EBattleItemDisuseReason* Reason);
	bool HandleDrop(int* InCount, EBattleItemDropReason* Reason);
	bool HandlePickup(struct FBattleItemPickupInfo* PickupInfo, EBattleItemPickupReason* Reason, TScriptInterface<class UItemContainerInterface>* ItemContainer);
	bool HandleUse(struct FBattleItemUseTarget* Target, EBattleItemUseReason* Reason);
};


}

