#include <EGL/egl.h>
#include <GLES3/gl3.h>
#include <list>
#include <vector>
#include <string.h>
#include <android/log.h>
#include <pthread.h>
#include <thread>
#include <cstring>
#include <jni.h>
#include <unistd.h>
#include <fstream>
#include <iostream>
#include <dlfcn.h>
#include "imgui/imgui.h"
#include "imgui/imgui_impl_android.h"
#include "imgui/imgui_impl_opengl3.h"
#include "SDK.hpp"
#include <cstring>
#include <string.h>
#include "And64InlineHook/And64InlineHook.hpp"
#include <cstdio>
#include <cinttypes>
#include <cstdint>
#include <cstring>
#include <libgen.h>
#include <thread>
#include <sstream>
#include <chrono>
#include "obfuscate.h"
#include "patch/MemoryPatch.h"

using namespace SDK;

bool initImGui = false;
int glWidth, glHeight;
uintptr_t UE4;
bool autoall, grenadehaha, gameinfosjs;
float density = 290.0f;

uintptr_t GetBaseAddress(const char *name) {
    uintptr_t base = 0;
    char line[512];

    FILE *f = fopen("/proc/self/maps", "r");

    if (!f) {
        return 0;
    }

    while (fgets(line, sizeof line, f)) {
        uintptr_t tmpBase;
        char tmpName[256];
        if (sscanf(line, "%" PRIXPTR "-%*" PRIXPTR " %*s %*s %*s %*s %s", &tmpBase, tmpName) > 0) {
            if (!strcmp(basename(tmpName), name)) {
                base = tmpBase;
                break;
            }
        }
    }

    fclose(f);
    return base;
}

uintptr_t string2Offset(const char *c) {
    int base = 16;
    // See if this function catches all possibilities.
    // If it doesn't, the function would have to be amended
    // whenever you add a combination of architecture and
    // compiler that is not yet addressed.
    static_assert(sizeof(uintptr_t) == sizeof(unsigned long)
                  || sizeof(uintptr_t) == sizeof(unsigned long long),
                  "Please add string to handle conversion for this architecture.");

    // Now choose the correct function ...
    if (sizeof(uintptr_t) == sizeof(unsigned long)) {
        return strtoul(c, nullptr, base);
    }

    // All other options exhausted, sizeof(uintptr_t) == sizeof(unsigned long long))
    return strtoull(c, nullptr, base);
}

#define HOOK_LIB(lib, offset, hook, orig) A64HookFunction((void *)(GetBaseAddress(OBFUSCATE(lib)) + string2Offset(OBFUSCATE(offset))), (void *)hook, (void **)&orig)
#define HOOK_LIB_NO_ORIG(lib, offset, ptr) A64HookFunction((void *)(GetBaseAddress(OBFUSCATE(lib)) + string2Offset(OBFUSCATE(offset))), (void *)ptr, NULL)

enum daLogType {
    daDEBUG = 3,
    daERROR = 6,
    daINFO = 4,
    daWARN = 5
};

#define TAG ("Putri")

#define LOGE(...) ((void)__android_log_print(daERROR, TAG, __VA_ARGS__))

std::vector<MemoryPatch> memoryPatches;
std::vector<uint64_t> offsetVector;

// Patching a offset without switch.
void patchOffset(const char *fileName, uint64_t offset, std::string hexBytes, bool isOn) {

    MemoryPatch patch = MemoryPatch::createWithHex(fileName, offset, hexBytes);

    //Check if offset exists in the offsetVector
    if (std::find(offsetVector.begin(), offsetVector.end(), offset) != offsetVector.end()) {
        //LOGE(OBFUSCATE("Already exists"));
        std::vector<uint64_t>::iterator itr = std::find(offsetVector.begin(), offsetVector.end(), offset);
        patch = memoryPatches[std::distance(offsetVector.begin(), itr)]; //Get index of memoryPatches vector
    } else {
        memoryPatches.push_back(patch);
        offsetVector.push_back(offset);
        //LOGI(OBFUSCATE("Added"));
    }

    if (!patch.isValid()) {
        LOGE(OBFUSCATE("Failing offset: 0x%llu, please re-check the hex"), offset);
        return;
    }
    if (isOn) {
        if (!patch.Modify()) {
            LOGE(OBFUSCATE("Something went wrong while patching this offset: 0x%llu"), offset);
        }
    } else {
        if (!patch.Restore()) {
            LOGE(OBFUSCATE("Something went wrong while restoring this offset: 0x%llu"), offset);
        }
    }
}

#define PATCH_LIB(lib, offset, hex) patchOffset(OBFUSCATE(lib), string2Offset(OBFUSCATE(offset)), OBFUSCATE(hex), true)

static UEngine *GEngine = 0;
UWorld *GetWorld() {
    while (!GEngine) {
		GEngine = UObject::FindObject<UEngine>("UAEGameEngine Transient.UAEGameEngine_1");
        sleep(1);
    }
    if (GEngine) {
        auto ViewPort = GEngine->GameViewport;

        if (ViewPort) {
            return ViewPort->World;
        }
    }
    return 0;
}

std::vector<AActor*> getPlayers() {
    std::vector<AActor*> list;

    auto World = GetWorld();
    if (!World) 
        return {};

    auto level = World->PersistentLevel;
    if (!level) 
        return {};

    auto BaseActor = *(uintptr_t*)((uintptr_t)level + 0xA0);
    int Count = *(int*)((uintptr_t)level + 0xA8);
    if (Count <= 0) 
        return {};

    for (int i = 0; i < Count; i++) {
        uintptr_t Actor = *(uintptr_t*)(BaseActor + (i * sizeof(uintptr_t)));
        
        if (Actor)
            list.push_back((AActor*)Actor);
    }
    return list;
}

void DrawESP(ImDrawList *draw) {
	
	ImGui::PushFontShadow(0xFF000000);

    int totalEnemies = 0, totalBots = 0;
    auto Actors = getPlayers();

    ASTExtraPlayerCharacter *localPlayer = 0;
    ASTExtraPlayerController *localController = 0;
	
	auto World = GetWorld();
	if (World) {
        auto NetDriver = World->NetDriver;
		if (NetDriver) {
            auto ServerConnection = NetDriver->ServerConnection;
            if (ServerConnection) {
                localController = (ASTExtraPlayerController *)ServerConnection->PlayerController;
            }
		}
	}
	
    if (localController) {
		localPlayer = (ASTExtraPlayerCharacter *)localController->AcknowledgedPawn;
		
		if (localPlayer) {
        	for (int i = 0; i < Actors.size(); i++) {
                auto Actor = Actors[i];
                
                if (Actors[i]->IsA(ASTExtraPlayerCharacter::StaticClass())) {
                    auto Player = (ASTExtraPlayerCharacter *) Actor;					
    
				    std::string barkle = Player->PlayerName.ToString();
                    float Distance = Player->GetDistanceTo(localPlayer) / 100.0f;
                        
				    if (!Player || barkle == "Barkle" || Distance > 350.0f || Player->TeamID == localPlayer->TeamID || Player->PlayerKey == localPlayer->PlayerKey || Player->bDead || !Player->RootComponent || Player->bHidden || Player->IsActorBeingDestroyed())
                        continue;
                    
                    int Colorhealth, healthOutline;
				    long LineColor;
                    if (Player->bEnsure)
				    {
                        totalBots++;
					    Colorhealth = IM_COL32(0, 255, 0, 120);//143, 242, 212, 110
					    healthOutline = IM_COL32(255, 255, 255, 255);
					    LineColor = IM_COL32(255, 255, 255, 255);
				    } else {
					    totalEnemies++;
					    Colorhealth = IM_COL32(255, 0, 255, 120);
					    healthOutline = IM_COL32(255, 255, 255, 255);
                        LineColor = IM_COL32(255, 0, 0, 255);
				    }               
						    
				    FVector HeadPos = Player->GetBonePos("Head", {});
                    ImVec2 HeadPosSC;
                    FVector upper_r = Player->GetBonePos("upperarm_r", {});
                    ImVec2 upper_rPoSC;
                    FVector lowerarm_r = Player->GetBonePos("lowerarm_r", {});
                    ImVec2 lowerarm_rPoSC;
                    FVector hand_r = Player->GetBonePos("hand_r", {});
                    ImVec2 hand_rPoSC;
                    FVector upper_l = Player->GetBonePos("upperarm_l", {});
                    ImVec2 upper_lPoSC;
                    FVector lowerarm_l = Player->GetBonePos("lowerarm_l", {});
                    ImVec2 lowerarm_lSC;
                    FVector hand_l = Player->GetBonePos("hand_l", {});
                    ImVec2 hand_lPoSC;
                    FVector thigh_l = Player->GetBonePos("thigh_l", {});
                    ImVec2 thigh_lPoSC;
                    FVector calf_l = Player->GetBonePos("calf_l", {});
                    ImVec2 calf_lPoSC;
                    FVector foot_l = Player->GetBonePos("foot_l", {});
                    ImVec2 foot_lPoSC;
                    FVector thigh_r = Player->GetBonePos("thigh_r", {});
                    ImVec2 thigh_rPoSC;
                    FVector calf_r = Player->GetBonePos("calf_r", {});
                    ImVec2 calf_rPoSC;
                    FVector foot_r = Player->GetBonePos("foot_r", {});
                    ImVec2 foot_rPoSC;
                    FVector neck_01 = Player->GetBonePos("neck_01", {});
                    ImVec2 neck_01PoSC;
                    FVector pelvis = Player->GetBonePos("pelvis", {});
                    ImVec2 pelvisPoSC;
                    FVector RootPos = Player->GetBonePos("Root", {});
                    ImVec2 RootPosSC;
					    
                    if (UGameplayStatics::ProjectWorldToScreen(localController, HeadPos, true, (FVector2D *) &HeadPosSC) && UGameplayStatics::ProjectWorldToScreen(localController, upper_r, true, (FVector2D *) &upper_rPoSC) && UGameplayStatics::ProjectWorldToScreen(localController, upper_l, true, (FVector2D *) &upper_lPoSC) && UGameplayStatics::ProjectWorldToScreen(localController, lowerarm_r, true, (FVector2D *) &lowerarm_rPoSC) && UGameplayStatics::ProjectWorldToScreen(localController, hand_r, true, (FVector2D *) &hand_rPoSC) && UGameplayStatics::ProjectWorldToScreen(localController, lowerarm_l, true, (FVector2D *) &lowerarm_lSC) && UGameplayStatics::ProjectWorldToScreen(localController, hand_l, true, (FVector2D *) &hand_lPoSC) && UGameplayStatics::ProjectWorldToScreen(localController, thigh_l, true, (FVector2D *) &thigh_lPoSC) && UGameplayStatics::ProjectWorldToScreen(localController, calf_l, true, (FVector2D *) &calf_lPoSC) && UGameplayStatics::ProjectWorldToScreen(localController, foot_l, true, (FVector2D *) &foot_lPoSC) && UGameplayStatics::ProjectWorldToScreen(localController, thigh_r, true, (FVector2D *) &thigh_rPoSC) && UGameplayStatics::ProjectWorldToScreen(localController, calf_r, true, (FVector2D *) &calf_rPoSC) && UGameplayStatics::ProjectWorldToScreen(localController, foot_r, true, (FVector2D *) &foot_rPoSC) && UGameplayStatics::ProjectWorldToScreen(localController, neck_01, true, (FVector2D *) &neck_01PoSC) && UGameplayStatics::ProjectWorldToScreen(localController, pelvis, true, (FVector2D *) &pelvisPoSC) && UGameplayStatics::ProjectWorldToScreen(localController, RootPos, true, (FVector2D *) &RootPosSC)) {
                        if (autoall) {
                            draw->AddLine({(float) glWidth / 2, 93}, {HeadPosSC.x, HeadPosSC.y - 53}, LineColor, 0);
					    }
						    
					    if (autoall) {
						    long right, left, lright, lleft, HeadCol, Hhh, Ghh;
									    
						    if (localController->LineOfSightTo(localController->PlayerCameraManager, Player->GetBonePos("Head", {}), true)) {
							    HeadCol = IM_COL32(0, 255, 0, 255);
						    } else {
                                HeadCol = IM_COL32(255, 0, 0, 255);
						    }
									    
						    if (localController->LineOfSightTo(localController->PlayerCameraManager, Player->GetBonePos("neck_01", {}), true)) {
							    Hhh = IM_COL32(0, 255, 0, 255);
						    } else {
							    Hhh = IM_COL32(255, 0, 0, 255);
						    }
									    
						    if (localController->LineOfSightTo(localController->PlayerCameraManager, Player->GetBonePos("Head", {}), true)
							    && localController->LineOfSightTo(localController->PlayerCameraManager, Player->GetBonePos("neck_01", {}), true)) {
							    Ghh = IM_COL32(0, 255, 0, 255);
						    } else {
							    Ghh = IM_COL32(255, 0, 0, 255);
						    }
									    
						    if (localController->LineOfSightTo(localController->PlayerCameraManager, Player->GetBonePos("neck_01", {}), true) 
							    && localController->LineOfSightTo(localController->PlayerCameraManager, Player->GetBonePos("clavicle_r", {}), true) 
							    || localController->LineOfSightTo(localController->PlayerCameraManager, Player->GetBonePos("upperarm_r", {}), true) 
							    || localController->LineOfSightTo(localController->PlayerCameraManager, Player->GetBonePos("lowerarm_r", {}), true)
							    || localController->LineOfSightTo(localController->PlayerCameraManager, Player->GetBonePos("hand_r", {}), true)
							    || localController->LineOfSightTo(localController->PlayerCameraManager, Player->GetBonePos("item_r", {}), true)) {
							    right = IM_COL32(0, 255, 0, 255);
						    } else {
							    right = IM_COL32(255, 0, 0, 255);
						    }
										    
						    if (localController->LineOfSightTo(localController->PlayerCameraManager, Player->GetBonePos("neck_01", {}), true) 
							    && localController->LineOfSightTo(localController->PlayerCameraManager, Player->GetBonePos("clavicle_l", {}), true) 
							    || localController->LineOfSightTo(localController->PlayerCameraManager, Player->GetBonePos("upperarm_l", {}), true) 
							    || localController->LineOfSightTo(localController->PlayerCameraManager, Player->GetBonePos("lowerarm_l", {}), true)
							    || localController->LineOfSightTo(localController->PlayerCameraManager, Player->GetBonePos("hand_l", {}), true)
							    || localController->LineOfSightTo(localController->PlayerCameraManager, Player->GetBonePos("item_l", {}), true)) {
							    left = IM_COL32(0, 255, 0, 255);
						    } else {
							    left = IM_COL32(255, 0, 0, 255);
						    }
										    
						    if (localController->LineOfSightTo(localController->PlayerCameraManager, Player->GetBonePos("pelvis", {}), true) 
							    && localController->LineOfSightTo(localController->PlayerCameraManager, Player->GetBonePos("thigh_r", {}), true) 
							    || localController->LineOfSightTo(localController->PlayerCameraManager, Player->GetBonePos("calf_r", {}), true) 
							    || localController->LineOfSightTo(localController->PlayerCameraManager, Player->GetBonePos("foot_r", {}), true)) {
							    lright = IM_COL32(0, 255, 0, 255);
						    } else {
							    lright = IM_COL32(255, 0, 0, 255);
						    }
										    
						    if (localController->LineOfSightTo(localController->PlayerCameraManager, Player->GetBonePos("pelvis", {}), true) 
							    && localController->LineOfSightTo(localController->PlayerCameraManager, Player->GetBonePos("thigh_l", {}), true) 
							    || localController->LineOfSightTo(localController->PlayerCameraManager, Player->GetBonePos("calf_l", {}), true) 
							    || localController->LineOfSightTo(localController->PlayerCameraManager, Player->GetBonePos("foot_l", {}), true)) {
							    lleft = IM_COL32(0, 255, 0, 255);
						    } else {
							    lleft = IM_COL32(255, 0, 0, 255);
						    }
									    
						    float boxWidth = 7.f - Distance * 0.03;
                            draw->AddCircle({HeadPosSC.x, HeadPosSC.y}, boxWidth, HeadCol, 0, 1.0f); 
    
                            //Skeleton
                            draw->AddLine({upper_rPoSC.x, upper_rPoSC.y},
                                        {neck_01PoSC.x, neck_01PoSC.y},
                                                                right,
                                                                1.4f);
                            draw->AddLine({upper_lPoSC.x, upper_lPoSC.y},
                                        {neck_01PoSC.x, neck_01PoSC.y},
                                                                left,
                                                                1.4f);
    
                                draw->AddLine({upper_rPoSC.x, upper_rPoSC.y},
                                                                {lowerarm_rPoSC.x, lowerarm_rPoSC.y},
                                                                right,
                                                                1.4f);
                                draw->AddLine({lowerarm_rPoSC.x, lowerarm_rPoSC.y},
                                                                {hand_rPoSC.x, hand_rPoSC.y},
                                                                right,
                                                                1.4f);
    
                                draw->AddLine({upper_lPoSC.x, upper_lPoSC.y},
                                                                {lowerarm_lSC.x, lowerarm_lSC.y},
                                                                left,
                                                                1.4f);
                                draw->AddLine({lowerarm_lSC.x, lowerarm_lSC.y},
                                                                {hand_lPoSC.x, hand_lPoSC.y},
                                                                left,
                                                                1.4f);
    
                                draw->AddLine({thigh_rPoSC.x, thigh_rPoSC.y},
                                                                {thigh_lPoSC.x, thigh_lPoSC.y},
                                                                lright,
                                                                1.4f);
    
                                draw->AddLine({thigh_lPoSC.x, thigh_lPoSC.y},
                                                                {calf_lPoSC.x, calf_lPoSC.y},
                                                                lleft,
                                                                1.4f);
                                draw->AddLine({calf_lPoSC.x, calf_lPoSC.y},
                                                                {foot_lPoSC.x, foot_lPoSC.y},
                                                                lleft,
                                                                1.4f);
    
                                draw->AddLine({thigh_rPoSC.x, thigh_rPoSC.y},
                                                                {calf_rPoSC.x, calf_rPoSC.y},
                                                                lright,
                                                                1.4f);
                                draw->AddLine({calf_rPoSC.x, calf_rPoSC.y},
                                                                {foot_rPoSC.x, foot_rPoSC.y},
                                                                lright,
                                                                1.4f);
    
                                draw->AddLine({neck_01PoSC.x, neck_01PoSC.y},
                                                                {pelvisPoSC.x, pelvisPoSC.y},
                                                                Hhh,
                                                                1.4f);
                                draw->AddLine({neck_01PoSC.x, neck_01PoSC.y},
                                                                {HeadPosSC.x, HeadPosSC.y},
                                                                Hhh,
                                                                1.4f);
                            }
        
                            if (autoall) {
                                int CurHP = (int) std::max(0, std::min((int) Player->Health, (int) Player->HealthMax));
                                int MaxHP = (int) Player->HealthMax;
    
							    long HPColor = IM_COL32(0, 255, 0, 200);
							    long HPColorS = IM_COL32(255, 255, 255, 200);
    
                                if (Player->Health == 0.0f && !Player->bDead) {
                                    HPColor = IM_COL32(255, 0, 0, 200);
								    HPColorS = IM_COL32(255, 0, 0, 200);
    
                                    CurHP = Player->NearDeathBreath;
                                    if (Player->NearDeatchComponent) {
                                        MaxHP = Player->NearDeatchComponent->BreathMax;
                                    }
                                }
    
                                float boxWidth = density / 6.0f;
                                boxWidth -= std::min(((boxWidth / 2) / 700.0f) * Distance, boxWidth / 2);
                                float boxHeight = boxWidth * 0.15f;
    
    
                                ImVec2 vStart = {HeadPosSC.x - (boxWidth / 2), HeadPosSC.y - (boxHeight * 2.5f)};
    
                                ImVec2 vEndFilled = {vStart.x + (CurHP * boxWidth / MaxHP), vStart.y + boxHeight};
                                ImVec2 vEndRect = {vStart.x + boxWidth, vStart.y + boxHeight};
                                        
                                if (Player->bEnsure) {                                       
								    draw->AddRectFilled(vStart, vEndRect, IM_COL32(0, 0, 0, 150), 0.0f);
								    draw->AddRectFilled(vStart, vEndFilled, HPColorS, 0.0f);
							    } else {
								    draw->AddRectFilled(vStart, vEndRect, IM_COL32(0, 0, 0, 150), 0.0f);
								    draw->AddRectFilled(vStart, vEndFilled, HPColor, 0.0f);
                                }
                            }											
    
						    if (autoall) {
							    std::string s;
							    s += "[";
                                s += std::to_string(Player->TeamID).substr(0, 2);
                                s += "] ";
							    if (Player->bEnsure) {
								    s += "Robot";
							    } else {
								    s += Player->PlayerName.ToString();
							    }
							    
							    auto textSize = ImGui::CalcTextSize2(s.c_str(), 0, 14.f);
							    draw->AddText2(NULL, 14.f, {HeadPosSC.x - (textSize.x / 2), HeadPosSC.y - 35.0f}, IM_COL32(255, 255, 255, 255), s.c_str());
							    draw->AddText(NULL, 14.f, {HeadPosSC.x - (textSize.x / 2), HeadPosSC.y - 35.0f}, IM_COL32(255, 255, 255, 255), s.c_str());
							    
							    std::string dista;
							    dista += std::to_string((int)Distance);
							    dista += "m";
								    
							    auto textSizee = ImGui::CalcTextSize2(dista.c_str(), 0, 14.f);
								    
							    draw->AddText2(NULL, 14.f, {RootPosSC.x - (textSizee.x / 2), RootPosSC.y + 3.f}, IM_COL32(255, 255, 255, 255), dista.c_str());
							    draw->AddText(NULL, 14.f, {RootPosSC.x - (textSizee.x / 2), RootPosSC.y + 3.f}, IM_COL32(255, 255, 255, 255), dista.c_str());
						    }
						    
						    if (autoall) {
							    auto WeaponManagerComponent = Player->WeaponManagerComponent;
							    if (WeaponManagerComponent) {
								    auto CurrentWeaponReplicated = (ASTExtraShootWeapon *)WeaponManagerComponent->CurrentWeaponReplicated;
								    if (CurrentWeaponReplicated) {
									    auto WeaponId = (int)CurrentWeaponReplicated->GetWeaponID();
									    if (WeaponId) {
										    std::string s;
										    s += CurrentWeaponReplicated->GetWeaponName().ToString();
										    
										    auto textSize = ImGui::CalcTextSize2(s.c_str(), 0, 14.0f);
										    draw->AddText2(NULL, 14.0f, {HeadPosSC.x - (textSize.x / 2), HeadPosSC.y - 50.0f}, IM_COL32(255, 255, 255, 255), s.c_str());
										    draw->AddText(NULL, 14.0f, {HeadPosSC.x - (textSize.x / 2), HeadPosSC.y - 50.0f}, IM_COL32(255, 255, 255, 255), s.c_str());
									    }
								    }
							    }
						    }
					    }
					    
					    /*if (autoall) {
						    
						    FVector2D gagag;
						    
						    if (UGameplayStatics::ProjectWorldToScreen(localController, Player->RootComponent->RelativeLocation, true, &gagag))
							    continue;
							    
						    long AlertCol;
						    if (localController->LineOfSightTo(localController->PlayerCameraManager, Player->RootComponent->RelativeLocation, true)) {
							    AlertCol = IM_COL32(0, 255, 0, 255);
						    } else {
							    if (Player->bEnsure) {
                                    AlertCol = IM_COL32(255, 255, 255, 255);
							    } else {
								    AlertCol = IM_COL32(255, 0, 0, 255);
							    }
						    } 
                            
						    bool out = false;
                            FVector MyPosition, EnemyPosition;
                            
						    ASTExtraVehicleBase * CurrentVehiclea = Player->CurrentVehicle;
                            if (CurrentVehiclea) {
                                MyPosition = CurrentVehiclea->RootComponent->RelativeLocation;
                            } else {
                                MyPosition = Player->RootComponent->RelativeLocation;
                            }
						    
                            ASTExtraVehicleBase * CurrentVehicle = localPlayer->CurrentVehicle;
                            if (CurrentVehicle) {
                                EnemyPosition = CurrentVehicle->RootComponent->RelativeLocation;
                            } else {
                                EnemyPosition = localPlayer->RootComponent->RelativeLocation;
                            }
						    
                            FVector EntityPos = WorldToRadar(localController->PlayerCameraManager->CameraCache.POV.Rotation.Yaw, MyPosition, EnemyPosition, NULL, NULL, FVector(glWidth, glHeight, 0), out);
                            FVector angle = FVector();
                            FVector forward = FVector((float)(glWidth / 2) - EntityPos.X, (float)(glHeight / 2) - EntityPos.Y, 0.0f);
                            VectorAnglesRadar(forward, angle);
                            const auto angle_yaw_rad = DEG2RAD(angle.Y + 180.f);
                            const auto new_point_x = (glWidth / 2) + (50.0f) / 2 * 8 * cosf(angle_yaw_rad);
                            const auto new_point_y = (glHeight / 2) + (50.0f) / 2 * 8 * sinf(angle_yaw_rad);
                            std::array<FVector, 3> points { FVector(new_point_x - ((90) / 4 + 3.5f) / 2, new_point_y - ((55) / 4 + 3.5f) / 2, 0.f), FVector(new_point_x + ((90) / 4 + 3.5f) / 4, new_point_y, 0.f), FVector(new_point_x - ((90) / 4 + 3.5f) / 2, new_point_y + ((55) / 4 + 3.5f) / 2, 0.f)};
                            RotateTriangle(points, angle.Y + 180.f);
                        
						    draw->AddCircleFilled(ImVec2(new_point_x, new_point_y), adjustedSizeAlert, AlertCol, 0);
					    }*/
				}
						
 		        if (grenadehaha) {
					if (Actors[i]->IsA(ASTExtraGrenadeBase::StaticClass())) {
                        auto Grenade = (ASTExtraGrenadeBase *) Actors[i];
								
                        float Distance = Grenade->GetDistanceTo(localPlayer) / 100.f;
                        
						if (!Grenade || !Grenade->RootComponent || Grenade->bHidden || Grenade->IsActorBeingDestroyed() || Distance > 120)
                            continue;
								
						std::string s;
						std::string l;
						std::string t;

						std::string classname = Grenade->GetName();

						FVector2D grenadePos;
						
                        if (UGameplayStatics::ProjectWorldToScreen(localController, Grenade->K2_GetActorLocation(), true, &grenadePos)) {
                            if (classname.find("BP_Projectile_FragGrenade_C") != std::string::npos) {
                                draw->AddCircleFilled(ImVec2(grenadePos.X, grenadePos.Y), 4, IM_COL32(255, 0, 0, 255), 0);
                                l += std::to_string((int) Distance);
                                l += "m";
								//t += "WARNING GRENADE";
								draw->AddLine({(float) glWidth / 2, (float) glHeight}, {grenadePos.X, grenadePos.Y}, IM_COL32(255, 0, 0, 255), 0);
                             } else if (classname.find("BP_Projectile_BurnGrenade_C") != std::string::npos) {
                                draw->AddCircleFilled(ImVec2(grenadePos.X, grenadePos.Y), 4, IM_COL32(255, 0, 0, 255), 0);
                                l += std::to_string((int) Distance);
                                l += "m";
									
								draw->AddLine({(float) glWidth / 2, (float) glHeight}, {grenadePos.X, grenadePos.Y}, IM_COL32(255, 0, 0, 255), 0);
                        	}                   
                        }
						if ((classname.find("BP_Projectile_FragGrenade_C") != std::string::npos) || (classname.find("BP_Projectile_BurnGrenade_C") != std::string::npos)) {
						 	t += "WARNING GRENADE";
						}
						auto textSize = ImGui::CalcTextSize2(t.c_str(), 0, 16.0f);
						auto textSizeee = ImGui::CalcTextSize2(l.c_str(), 0, 17.0f);
						draw->AddText(NULL, 17.0f, {grenadePos.X - (textSizeee.x / 2), grenadePos.Y + 5}, IM_COL32(255, 255, 255, 255), l.c_str());
						draw->AddText2(NULL, 16.0f, {glWidth / 2 - (textSize.x / 2), 110}, IM_COL32(255, 0, 0, 220), t.c_str());
                    }
				}
                             
			    if (gameinfosjs) {     
                    if (Actors[i]->IsA(ASTExtraGameStateBase::StaticClass())) {
                        auto InGame = (ASTExtraGameStateBase *) Actors[i];
                        std::string s;
  						s += "\nTotal Player = ";
  						s += std::to_string((int)InGame->PlayerNum);
  						s += "\nTeam In Match = ";
  						s += std::to_string((int)InGame->AliveTeamNum);
  						s += "\nPlayer Alive = ";
  						s += std::to_string((int)InGame->AlivePlayerNum);
							
						draw->AddText2(NULL, 20.0f, {(float)glWidth / 2.0f, 120.0f}, IM_COL32(255, 255, 255, 255), s.c_str());
					}
                }
            }
		}
		std::string s = "Player ";
        s += std::to_string(totalEnemies);
		s += " | ";
		s += std::to_string(totalBots);
		s += " Robot";

		auto textSize = ImGui::CalcTextSize2(s.c_str(), 0, 18.0f);
		draw->AddText2(NULL, 18.0f, {glWidth / 2 - (textSize.x / 2), 75}, IM_COL32(255, 0, 0, 255), s.c_str());

   		if (totalEnemies || totalBots > 0) {
	   		autoall = true;
   		} else {
	   		autoall = false;
   		}
   
   		if (localController) {
	   		grenadehaha = true;
	   		gameinfosjs = true;
   		} else {
	   		grenadehaha = false;
	   		gameinfosjs = false;
		}
	}
}

EGLBoolean (*orig_eglSwapBuffers)(EGLDisplay dpy, EGLSurface surface);
EGLBoolean _eglSwapBuffers(EGLDisplay dpy, EGLSurface surface) {
    eglQuerySurface(dpy, surface, EGL_WIDTH, &glWidth);
    eglQuerySurface(dpy, surface, EGL_HEIGHT, &glHeight);
   
	if (!initImGui) {
    	ImGui::CreateContext();
		ImGui::GetStyle().ScaleAllSizes(2.0f);
      
        ImGui_ImplAndroid_Init();
        ImGui_ImplOpenGL3_Init(OBFUSCATE("#version 300 es"));

        ImGuiIO &io = ImGui::GetIO();

        io.ConfigWindowsMoveFromTitleBarOnly = true;
        io.IniFilename = NULL;
	
        ImFontConfig cfg;
        cfg.SizePixels = 20.0f;
        io.Fonts->AddFontDefault(&cfg);
		io.Fonts->Flags |= ImFontAtlasFlags_NoPowerOfTwoHeight;
        
        initImGui = true;
    }
	
    ImGuiIO &io = ImGui::GetIO();
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplAndroid_NewFrame(glWidth, glHeight);
    ImGui::NewFrame();
    DrawESP(ImGui::GetBackgroundDrawList());
	
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    return orig_eglSwapBuffers(dpy, surface);
}

typedef uint8_t  _BYTE;
typedef uint16_t _WORD;
typedef uint32_t _DWORD;
typedef uint64_t _QWORD;

uint64_t __fastcall hsub_218DE8(_QWORD *a1, _BYTE *a2, int a3, uint64_t a4)
{
    if (!a1) return 0LL;
    _BYTE local_buf[4] = {0};
    _BYTE *buf = a2 ? a2 : local_buf;
    unsigned long long pack_lo = (unsigned int)a3; 
    unsigned long long pack_hi = (unsigned long long)time(NULL);
    unsigned long long v10 = a1[3];
    unsigned long long v11 = a1[9];
    if (a3 == 99) {
        return 0LL;
    }
    if ( ((v11 > 1 && v11 <= (unsigned int)(a3 + 1)) || v11 > 3 || v10 == 0) && (v10 < 3) )
     {
        return 0LL;
    }
    return 0LL;
}

uint64_t (*oGetPlayerCharacterSafety)(uint64_t a1, uint64_t a2, uint64_t* a3);
uint64_t hGetPlayerCharacterSafety(uint64_t a1, uint64_t a2, uint64_t* a3)
{
    uint64_t v3 = *(_QWORD*)(a2 + 32);

    if (v3)
        ++v3;

    *(_QWORD*)(a2 + 32) = v3;

    *a3 = 0LL;

    return 0;
}

void *bypass_thread(void *) {
	do {
		sleep(1);
	} while (!UE4);
HOOK_LIB_NO_ORIG("libanogs.so", "0x213000", hsub_218DE8);//CRASHFIXER
PATCH_LIB("libUE4.so", "0x637157C", "00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so", "0x6371490", "00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so", "0x7CA7940", "00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so", "0xC8760B0", "00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so", "0xC875F70", "C0 03 5F D6");
HOOK_LIB("libUE4.so", "0x6C9C8FC", hGetPlayerCharacterSafety, oGetPlayerCharacterSafety);
PATCH_LIB("libanogs.so", "0x330494", "00 00 80 D2 C0 03 5F D6");//CRC calculation
PATCH_LIB("libanogs.so", "0x39F56C", "00 00 80 D2 C0 03 5F D6");//CRC-CHECK 2
	return NULL;
}

void *main_thread(void *) {
	UE4 = GetBaseAddress("libUE4.so");
    while (!UE4){
    	UE4 = GetBaseAddress("libUE4.so");
        sleep(1);
	}

	FName::GNames = ((TNameEntryArray * (*)()) (UE4 + 0x83de2d4))();
    UObject::GUObjectArray = (FUObjectArray *) (UE4 + 0xe74e0f0);
	
    A64HookFunction((void *) (UE4 + 0xC876C60), (void *) _eglSwapBuffers, (void **) &orig_eglSwapBuffers);
	return NULL;
}

__attribute__((constructor)) void _init() {
    pthread_t t;
    pthread_create(&t, NULL, main_thread, NULL);
    //pthread_create(&t, NULL, bypass_thread, NULL);
}
