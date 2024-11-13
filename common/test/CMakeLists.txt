set(TEST_SOURCES
    src/main.cpp
    src/test_maps.cpp
    src/test_eof.cpp
    src/test_typedefs.cpp
)

add_executable(common_test ${TEST_SOURCES})

target_compile_features(common_test PUBLIC cxx_std_17)

target_link_libraries(common_test
    common
    fmt::fmt
    doctest::doctest
)

# Clean test_data from previous builds 
add_custom_command(
    TARGET common_test POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E remove_directory
            $<TARGET_FILE_DIR:common_test>/test_data
)

# Copy test_data to build directory
add_custom_command(
    TARGET common_test POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${CMAKE_CURRENT_SOURCE_DIR}/test_data
            $<TARGET_FILE_DIR:common_test>/test_data
)
