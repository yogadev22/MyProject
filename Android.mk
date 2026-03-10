LOCAL_PATH := $(call my-dir)
MAIN_LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE    := mono

LOCAL_CFLAGS := -Wno-error=format-security -fvisibility=hidden -ffunction-sections -fdata-sections -w
LOCAL_CFLAGS += -fno-rtti -fno-exceptions -fpermissive
LOCAL_CPPFLAGS := -Wno-error=format-security -fvisibility=hidden -ffunction-sections -fdata-sections -w -Werror -s -std=c++17
LOCAL_CPPFLAGS += -Wno-error=c++11-narrowing -fms-extensions -fno-rtti -fno-exceptions -fpermissive
LOCAL_LDFLAGS += -Wl,--gc-sections,--strip-all, -llog
LOCAL_ARM_MODE := arm

LOCAL_C_INCLUDES += $(MAIN_LOCAL_PATH)

LOCAL_SRC_FILES 		:=  main.cpp \
        exe_right.cpp \
        patch/KittyMemory.cpp \
        patch/MemoryPatch.cpp \
        patch/MemoryBackup.cpp \
        patch/KittyUtils.cpp \
        imgui/imgui.cpp \
        imgui/imgui_draw.cpp \
        imgui/imgui_demo.cpp \
        imgui/imgui_tables.cpp \
        imgui/imgui_widgets.cpp \
        imgui/backends/imgui_impl_android.cpp \
        imgui/backends/imgui_impl_opengl3.cpp \
        SDK/PUBGM_Basic.cpp \
        SDK/PUBGM_Basic_functions.cpp \
        SDK/PUBGM_Engine_functions.cpp \
        SDK/PUBGM_Client_functions.cpp \
        SDK/PUBGM_CoreUObject_functions.cpp \
        SDK/PUBGM_ShadowTrackerExtra_functions.cpp \
        And64InlineHook/And64InlineHook.cpp \

LOCAL_CPP_FEATURES                      := exceptions
LOCAL_LDLIBS                            := -llog -landroid -lEGL -lGLESv3 -lz
include $(BUILD_SHARED_LIBRARY)
