cmake_minimum_required(VERSION 3.16)

add_executable(${PROJECT_NAME}-directory-test directory_test.cpp)
target_link_libraries(${PROJECT_NAME}-directory-test ${PROJECT_NAME})

# prepared necessary directory for test
add_custom_command(
    TARGET ${PROJECT_NAME}-directory-test
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E
        make_directory $<TARGET_FILE_DIR:${PROJECT_NAME}-directory-test>/test_exist_dir
        )

add_test(
    NAME directory-exist_directory
    COMMAND $<TARGET_FILE:${PROJECT_NAME}-directory-test> exist_directory
    )
    set_property(
        TEST directory-exist_directory
        PROPERTY LABELS lib directory stdlib
        )

add_test(
    NAME directory-make_directory
    COMMAND $<TARGET_FILE:${PROJECT_NAME}-directory-test> make_directory
    )
    set_property(
        TEST directory-make_directory
        PROPERTY LABELS lib directory stdlib
        )

