cmake_minimum_required(VERSION 3.5)
project(Grasshopper VERSION 0.0.1 DESCRIPTION "A Grasshopper's game engine")
# conan cmake_find_package integration
set(CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR})

include(GNUInstallDirs)

include(cmake/ide.cmake)

# create names for targets
set(GRASSHOPPER_SHARED "${PROJECT_NAME}")
set(GRASSHOPPER_STATIC "${PROJECT_NAME}_static")

#TODO: dont use glob
file(GLOB_RECURSE grasshopper_src "src/*.cpp" "src/*.hpp")


######################################################
#			Targets
#######################################################

add_library(${GRASSHOPPER_STATIC} STATIC ${grasshopper_src})
add_library("${PROJECT_NAME}::${GRASSHOPPER_STATIC}" ALIAS ${GRASSHOPPER_STATIC})

add_library(${GRASSHOPPER_SHARED} SHARED ${grasshopper_src})
add_library("${PROJECT_NAME}::${GRASSHOPPER_SHARED}" ALIAS ${GRASSHOPPER_SHARED})

#####################################################################
#			properties
##########################################################################
set_property(TARGET ${GRASSHOPPER_SHARED} PROPERTY POSITION_INDEPENDENT_CODE ON)

#####################################################################
#			Dependencies
##########################################################################
set(VENDOR_DIR ${CMAKE_CURRENT_SOURCE_DIR}/vendor)

find_package(spdlog REQUIRED)

#spdlog_enable_warnings(${GRASSHOPPER_BUILD_NAME})
#spdlog_enable_warnings(${GRASSHOPPER_BUILD_NAME}_static)

target_link_libraries(${GRASSHOPPER_SHARED} PUBLIC spdlog::spdlog)
target_link_libraries(${GRASSHOPPER_STATIC} PUBLIC spdlog::spdlog)

##########################################################################
#  			Target Includes
#########################################################################
target_include_directories(${GRASSHOPPER_STATIC}
	PUBLIC
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    	$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Grasshopper
)

target_include_directories(${GRASSHOPPER_SHARED}
	PUBLIC
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
		$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
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
set(INSTALL_CONFIGDIR ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME})

install(
	TARGETS
		${GRASSHOPPER_SHARED}
		${GRASSHOPPER_STATIC}
	EXPORT
		"${PROJECT_NAME}Targets"
	LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
	ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
	RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

install(
	EXPORT "${PROJECT_NAME}Targets"
	FILE GrasshopperTargets.cmake
	NAMESPACE "${PROJECT_NAME}::"
	DESTINATION ${INSTALL_CONFIGDIR}
)

install(
	DIRECTORY include/Grasshopper
	DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

#####################
# ConfigVersion file
##
include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/GrasshopperConfigVersion.cmake
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY AnyNewerVersion
)

configure_package_config_file(
    ${CMAKE_CURRENT_LIST_DIR}/cmake/GrasshopperConfig.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/GrasshopperConfig.cmake
    INSTALL_DESTINATION ${INSTALL_CONFIGDIR}
)

## Install all the helper files
install(
    FILES
      ${CMAKE_CURRENT_BINARY_DIR}/GrasshopperConfig.cmake
      ${CMAKE_CURRENT_BINARY_DIR}/GrasshopperConfigVersion.cmake
    DESTINATION ${INSTALL_CONFIGDIR}
)