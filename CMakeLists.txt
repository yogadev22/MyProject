cmake_minimum_required(VERSION 3.10)

project(yogs)

file(GLOB anjay "*.cpp" "imgui/*.cpp" "patch/*.cpp" "And64InlineHook/*.cpp")

add_library(mono SHARED $(anjay) 
        imgui/backends/imgui_impl_android.cpp 
        imgui/backends/imgui_impl_opengl3.cpp
        SDK/PUBGM_Basic.cpp
        SDK/PUBGM_Basic_functions.cpp
        SDK/PUBGM_Engine_functions.cpp
        SDK/PUBGM_Client_functions.cpp
        SDK/PUBGM_CoreUObject_functions.cpp
        SDK/PUBGM_ShadowTrackerExtra_functions.cpp
)

target_include_directories(mono PRIVATE $(CMAKE_CURRENT_SOURCE_DIR))
target_link_libraries(mono z log android EGL GLESv3)