cmake_minimum_required(VERSION 3.5)
project(Grasshopper VERSION 0.0.1 DESCRIPTION "A Grasshopper's game engine")

include(cmake/ide.cmake)

# create names for targets
set(GRASSHOPPER_SHARED "${PROJECT_NAME}")
set(GRASSHOPPER_STATIC "${PROJECT_NAME}_static")

file(GLOB_RECURSE grasshopper_src "src/*.cpp" "src/*.hpp")


######################################################
#			Targets
#######################################################

add_library(${GRASSHOPPER_STATIC} STATIC ${grasshopper_src})

add_library(${GRASSHOPPER_SHARED} SHARED ${grasshopper_src})

#####################################################################
#			Dependencies
##########################################################################
set(VENDOR_DIR ${CMAKE_CURRENT_SOURCE_DIR}/vendor)

#### 	spdlog   ##################
#TODO: replace with find() command
if(NOT TARGET spdlog)
    add_subdirectory(${VENDOR_DIR}/spdlog)
endif()

#spdlog_enable_warnings(${GRASSHOPPER_BUILD_NAME})
#spdlog_enable_warnings(${GRASSHOPPER_BUILD_NAME}_static)

link_libraries(spdlog::spdlog)

##########################################################################
#  			Target Includes
#########################################################################
target_include_directories(${GRASSHOPPER_STATIC}
	PUBLIC
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
		$<INSTALL_INTERFACE:include/Grasshopper>
		${VENDOR_DIR}/spdlog/include
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Grasshopper
)

target_include_directories(${GRASSHOPPER_SHARED}
	PUBLIC
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
		$<INSTALL_INTERFACE:include/Grasshopper>
		${VENDOR_DIR}/spdlog/include
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Grasshopper
)


# PLATFORM SPECIFIC DEFINES
if (CMAKE_SYSTEM_NAME STREQUAL "Linux")
	add_compile_definitions(GH_PLATFORM_LINUX)
	target_compile_definitions(${GRASSHOPPER_SHARED} PRIVATE GH_BUILD_SO)
elseif(CMAKE_SYSTEM_NAME STREQUAL "Windows")
	add_definitions(GH_PLATFORM_WINDOWS)
	target_compile_definitions(${GRASSHOPPER_SHARED} PRIVATE GH_BUILD_DLL)
endif()

#TODO: set up install/export
# export(TARGETS ${GRASSHOPPER_SHARED} ${GRASSHOPPER_STATIC} NAMESPACE Grasshopper:: FILE GrasshopperTargets.cmake)
