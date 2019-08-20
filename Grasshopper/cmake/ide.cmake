#---------------------------------------------------------------------------------------
# IDE support for headers
#---------------------------------------------------------------------------------------
set(GRASSHOPPER_HEADERS_DIR "${CMAKE_CURRENT_LIST_DIR}/../include/")

file(GLOB GRASSHOPPER_TOP_HEADERS "${GRASSHOPPER_HEADERS_DIR}/Grasshopper/*.h")
set(GRASSHOPPER_ALL_HEADERS ${GRASSHOPPER_TOP_HEADERS})

source_group("Header Files\\Grasshopper" FILES ${SPDLOG_TOP_HEADERS})

