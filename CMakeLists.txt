cmake_minimum_required(VERSION 3.12)
set(CMAKE_SUPPRESS_REGENERATION true)

set(FOLDER_NAME ImApp)
set(PROJECT_NAME ImApp)

set (CMAKE_CXX_STANDARD 17)

project(${PROJECT_NAME} CXX)

include(CMake/CMakeMacros.txt)

# Dunno
set_property(GLOBAL PROPERTY USE_FOLDERS ON)



# Parameters to build GLFW with
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "")
set(GLFW_BUILD_TESTS OFF CACHE BOOL "")
set(GLFW_BUILD_DOCS OFF CACHE BOOL "")
set(GLFW_INSTALL OFF CACHE BOOL "")

# Excluding compiler warnings with project define 
#if(WIN32)
#	add_definitions(-D_CRT_SECURE_NO_WARNINGS)
#endif()

# Adding submodules CmakeLists to this one
add_subdirectory(submodules/src/GLFW)

include_directories(.)
include_directories(submodules/src)
include_directories(submodules/src/imgui)
include_directories(submodules/src/GLFW/include)
include_directories(submodules/glad/include)
include_directories(submodules/src/stb_image)

# Setting macros for glad linking
set(GLAD_SOURCES submodules/glad/src/glad.c submodules/glad/include/glad/glad.h)

add_library(glad ${GLAD_SOURCES})

set_property(TARGET glfw          PROPERTY FOLDER "ThirdPartyLibraries")
set_property(TARGET glad          PROPERTY FOLDER "ThirdPartyLibraries")

file(GLOB_RECURSE SRC_FILES LIST_DIRECTORIES false RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} ImApp/src/*.c??)
file(GLOB_RECURSE HEADER_FILES LIST_DIRECTORIES false RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} ImApp/src/*.h)

include_directories(ImApp/src/)

add_library(${PROJECT_NAME} STATIC ${SRC_FILES} ${HEADER_FILES})

SETUP_GROUPS("${SRC_FILES}")
SETUP_GROUPS("${HEADER_FILES}")

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDART 20)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD_REQUIRED ON)

if(MSVC)
	add_definitions(-D_CONSOLE)
	set_property(TARGET ${PROJECT_NAME} PROPERTY VS_DEBUGGER_WORKING_DIRECTORY  "${CMAKE_SOURCE_DIR}")
endif()

target_link_libraries(${PROJECT_NAME} glfw glad)

add_subdirectory(sandbox ${CMAKE_CURRENT_BINARY_DIR}/Sandbox)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT Sandbox)