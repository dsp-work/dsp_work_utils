cmake_minimum_required(VERSION 3.16)

add_executable(${PROJECT_NAME}-stack_backtrace_operation-test
    stack_backtrace_operation_test.cpp
    with_test.cpp)
target_link_libraries(${PROJECT_NAME}-stack_backtrace_operation-test ${PROJECT_NAME})

add_test(
    NAME stack_backtrace_operation-basic_backtrace
    COMMAND $<TARGET_FILE:${PROJECT_NAME}-stack_backtrace_operation-test> basic_backtrace
    )
    set_property(
        TEST stack_backtrace_operation-basic_backtrace
        PROPERTY LABELS lib stack_backtrace_operation
        )
