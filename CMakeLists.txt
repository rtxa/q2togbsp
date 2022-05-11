cmake_minimum_required(VERSION 3.0.0)
project(q2togbsp)

set(EXECUTABLE_OUTPUT_PATH ./${CMAKE_BUILD_TYPE})

set(CMAKE_CXX_STANDARD 17)

set(MY_SOURCE_FILES
    src/q2togbsp.cpp
    src/converter/QuakeToGenesis.cpp
    src/math/Vector3f.cpp
    src/parser/QuakeParser.cpp
    src/structures/GenesisBrush.cpp
    src/structures/GenesisEntity.cpp
    src/structures/GenesisFace.cpp
    src/structures/GenesisMap.cpp
    src/structures/QuakeBrush.cpp
    src/structures/QuakeEntity.cpp
    src/structures/QuakeFace.cpp
    src/structures/QuakeMap.cpp
    src/utils/InputParser.cpp
    src/utils/StringTokenizer.cpp
    src/writer/GBSPWriter.cpp
 )

add_subdirectory("lib/fmt")
add_subdirectory("lib/argparse")

add_executable(${PROJECT_NAME} ${MY_SOURCE_FILES})

target_include_directories(${PROJECT_NAME} PUBLIC "src")

target_link_libraries(${PROJECT_NAME} fmt::fmt)
target_link_libraries(${PROJECT_NAME} argparse::argparse)
