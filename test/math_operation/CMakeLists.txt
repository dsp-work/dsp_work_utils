cmake_minimum_required(VERSION 3.16)

add_executable(${PROJECT_NAME}-math_operation-test math_operation_test.cpp)
target_link_libraries(${PROJECT_NAME}-math_operation-test ${PROJECT_NAME})

add_test(
    NAME math_operation-pow2
    COMMAND $<TARGET_FILE:${PROJECT_NAME}-math_operation-test> pow2
    )
    set_property(
        TEST math_operation-pow2
        PROPERTY LABELS lib math_operation
        )
