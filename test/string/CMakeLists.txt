cmake_minimum_required(VERSION 3.16)

add_executable(${PROJECT_NAME}-string-test string_test.cpp)
target_link_libraries(${PROJECT_NAME}-string-test ${PROJECT_NAME})

add_test(
    NAME string-format
    COMMAND $<TARGET_FILE:${PROJECT_NAME}-string-test> format
    )
    set_property(
        TEST string-format
        PROPERTY LABELS lib string
        )

add_test(
    NAME string-split_char
    COMMAND $<TARGET_FILE:${PROJECT_NAME}-string-test> split_char
    )
    set_property(
        TEST string-split_char
        PROPERTY LABELS lib string
        )

