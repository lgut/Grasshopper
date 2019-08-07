cmake_minimum_required(VERSION 3.5)
project(Grasshopper VERSION 0.0.1)

# creates static libraries by default, add SHARED after library name to create dynamic library
# there is a third lib type called MODULE

# create name for build
set(GRASSHOPPER_BUILD_NAME "${PROJECT_NAME}")

file(GLOB_RECURSE grasshopper_src "src/*.cpp")

add_library(${GRASSHOPPER_BUILD_NAME}_static STATIC ${grasshopper_src})

add_library(${GRASSHOPPER_BUILD_NAME} SHARED ${grasshopper_src})

target_include_directories(${GRASSHOPPER_BUILD_NAME}_static
	PUBLIC
		$<INSTALL_INTERFACE:include>
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
	PRIVATE
		${CMAKE_CURRENT_SOURCE_DIR}/src/Grasshopper
)

target_include_directories(${GRASSHOPPER_BUILD_NAME}
	PUBLIC
		$<INSTALL_INTERFACE:include>
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
		${CMAKE_CURRENT_SOURCE_DIR}/src/Grasshopper
)

# PLATFORM SPECIFIC DEFINES
if (CMAKE_SYSTEM_NAME STREQUAL "Linux")
	add_compile_definitions(GH_PLATFORM_LINUX)
	target_compile_definitions(${GRASSHOPPER_BUILD_NAME} PRIVATE GH_BUILD_SO)
elseif(CMAKE_SYSTEM_NAME STREQUAL "Windows")
	add_definitions(GH_PLATFORM_WINDOWS)
	target_compile_definitions(${GRASSHOPPER_BUILD_NAME} PRIVATE GH_BUILD_DLL)
endif()
