## BE AWARE that this `CMakeLists.txt` SHOULD NOT be used as an example of how to use the library.
## You can find instruction on how to add this library into your CMake project in the root `README.md` file.


cmake_minimum_required(VERSION 3.26)
project(ImguiInitializer VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 17)


# --------------------------- Create static library ---------------------------
set (SOURCES
        ImguiInitializer.cpp
        ImguiInitializer.h
)

add_library(${PROJECT_NAME} STATIC ${SOURCES})

# This makes headers available in the project were library is used as if
# `target_include_directories` was used there instead.
target_include_directories(${PROJECT_NAME}
        PUBLIC
            "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>"
        INTERFACE
            "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>"
)
# -----------------------------------------------------------------------------


# ---------------------- Add Dear ImGui to static library ---------------------
set(IMGUI_PATH ${CMAKE_CURRENT_LIST_DIR}/imgui-1.90)

file(GLOB IMGUI_FILES
        ${IMGUI_PATH}/imgui*
        ${IMGUI_PATH}/backends/imgui_impl_glfw.*
        ${IMGUI_PATH}/backends/imgui_impl_opengl3.*
)

target_sources(${PROJECT_NAME} PRIVATE ${IMGUI_FILES})

target_include_directories(${PROJECT_NAME}
        PUBLIC ${IMGUI_PATH} ${IMGUI_PATH}/backends
)
# -----------------------------------------------------------------------------


# ------------------------ Add GLFW to static library -------------------------
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(glfw-3.3.8)
target_link_libraries(${PROJECT_NAME} PUBLIC glfw)

find_package(OpenGL REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE OpenGL::GL)
# -----------------------------------------------------------------------------
