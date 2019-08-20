cmake_minimum_required(VERSION 3.5)
project(Sandbox VERSION 0.0.1)

file(GLOB_RECURSE sandbox_src "src/*.cpp" "src/*.hpp")

add_executable(${PROJECT_NAME} ${sandbox_src})
add_executable(${PROJECT_NAME}_static ${sandbox_src})

include_directories(${GRASSHOPPER_HEADERS_DIR})

target_link_libraries(${PROJECT_NAME} Grasshopper)
target_link_libraries(${PROJECT_NAME}_static Grasshopper_static)