cmake_minimum_required(VERSION 3.16)

add_executable(${PROJECT_NAME}-string_operation-test string_operation_test.cpp)
target_link_libraries(${PROJECT_NAME}-string_operation-test ${PROJECT_NAME})

add_test(
    NAME string_operation-format
    COMMAND $<TARGET_FILE:${PROJECT_NAME}-string_operation-test> format
    )
    set_property(
        TEST string_operation-format
        PROPERTY LABELS lib string_operation
        )

add_test(
    NAME string_operation-split_char
    COMMAND $<TARGET_FILE:${PROJECT_NAME}-string_operation-test> split_char
    )
    set_property(
        TEST string_operation-split_char
        PROPERTY LABELS lib string_operation
        )

