set(TEST_SOURCES
    main.cpp
    test_maps.cpp
)

add_executable(common_test ${TEST_SOURCES})

target_link_libraries(common_test
    common
    fmt::fmt
    doctest::doctest
)

# Copy test_data into the build dir
add_custom_command(
    TARGET common_test POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${CMAKE_CURRENT_SOURCE_DIR}/test_data
            $<TARGET_FILE_DIR:common_test>/test_data
)
