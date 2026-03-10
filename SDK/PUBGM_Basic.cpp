// PUBG_VNG -64bit (4.2.0) SDK by BangJO [Z] DM @isar_hackJO To Buy Tool SDK

#include "../SDK.hpp"

namespace SDK
{
TNameEntryArray* FName::GNames = nullptr;
FUObjectArray* UObject::GUObjectArray = nullptr;
//---------------------By BangJO---------------------------
bool FWeakObjectPtr::IsValid() const
{
    if (ObjectSerialNumber == 0)
    {
        return false;
    }
    if (ObjectIndex < 0)
    {
        return false;
    }
    auto ObjectItem = UObject::GetGlobalObjects().GetItemByIndex(ObjectIndex);
    if (!ObjectItem)
    {
        return false;
    }
    if (!SerialNumbersMatch(ObjectItem))
    {
        return false;
    }
    return !(ObjectItem->IsUnreachable() || ObjectItem->IsPendingKill());
}
//---------------------By BangJO---------------------------
UObject* FWeakObjectPtr::Get() const
{
    if (IsValid())
    {
        auto ObjectItem = UObject::GetGlobalObjects().GetItemByIndex(ObjectIndex);
        if (ObjectItem)
        {
            return ObjectItem->Object;
        }
    }
    return nullptr;
}
//---------------------By BangJO---------------------------
}

