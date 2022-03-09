cmake_minimum_required(VERSION 3.16)

add_executable(${PROJECT_NAME}-directory_operation-test directory_operation_test.cpp)
target_link_libraries(${PROJECT_NAME}-directory_operation-test ${PROJECT_NAME})

# prepared necessary directory for test
add_custom_command(
    TARGET ${PROJECT_NAME}-directory_operation-test
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E
        make_directory $<TARGET_FILE_DIR:${PROJECT_NAME}-directory_operation-test>/test_exist_dir
        )

add_test(
    NAME directory_operation-exist_directory
    COMMAND $<TARGET_FILE:${PROJECT_NAME}-directory_operation-test> exist_directory
    )
    set_property(
        TEST directory_operation-exist_directory
        PROPERTY LABELS lib directory_operation stdlib_operation
        )

add_test(
    NAME directory_operation-make_directory
    COMMAND $<TARGET_FILE:${PROJECT_NAME}-directory_operation-test> make_directory
    )
    set_property(
        TEST directory_operation-make_directory
        PROPERTY LABELS lib directory_operation stdlib_operation
        )

