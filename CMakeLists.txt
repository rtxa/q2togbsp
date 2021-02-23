cmake_minimum_required (VERSION 3.0.0)
 
project (q2togbsp)
set(EXECUTABLE_OUTPUT_PATH ./${CMAKE_BUILD_TYPE})

set(CMAKE_CXX_STANDARD 20)
 
file(
    GLOB_RECURSE
    MY_SOURCE_FILES
    src/*
)
 
add_executable (${PROJECT_NAME} ${MY_SOURCE_FILES})
