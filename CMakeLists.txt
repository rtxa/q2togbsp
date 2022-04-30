cmake_minimum_required(VERSION 3.0.0)
project(q2togbsp)

set(EXECUTABLE_OUTPUT_PATH ./${CMAKE_BUILD_TYPE})

set(CMAKE_CXX_STANDARD 20)

file(
    GLOB_RECURSE
    MY_SOURCE_FILES
    CONFIGURE_DEPENDS
    src/*.cpp
    src/converter/*.cpp
    src/math/*.cpp
    src/parser/*.cpp
    src/structures/*.cpp
    src/utils/*.cpp
    src/writer/*.cpp
)
add_subdirectory("lib/fmt")

add_executable(${PROJECT_NAME} ${MY_SOURCE_FILES})

target_include_directories(${PROJECT_NAME} PUBLIC "src")
target_link_libraries(${PROJECT_NAME} fmt::fmt)
