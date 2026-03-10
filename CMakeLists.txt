cmake_minimum_required(VERSION 3.10)

project(yogs)

file(GLOB anjay "imgui/*.cpp" "patch/*.cpp" "And64InlineHook/*.cpp")

add_library(mono SHARED ${anjay}
main.cpp
        imgui/backends/imgui_impl_android.cpp 
        imgui/backends/imgui_impl_opengl3.cpp
        SDK/PUBGM_Basic.cpp
        SDK/PUBGM_Basic_functions.cpp
        SDK/PUBGM_Engine_functions.cpp
        SDK/PUBGM_Client_functions.cpp
        SDK/PUBGM_CoreUObject_functions.cpp
        SDK/PUBGM_ShadowTrackerExtra_functions.cpp
)

target_compile_options(native-lib PRIVATE
    -O2
    -fvisibility=hidden
    -ffunction-sections
    -fdata-sections
    -fno-rtti
    -fno-exceptions
)

target_link_options(mono PRIVATE
    -Wl,--gc-sections
    -Wl,--strip-all
)

target_include_directories(mono PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(mono z log android EGL GLESv3)
