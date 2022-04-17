cmake_minimum_required(VERSION 3.16)

add_executable(${PROJECT_NAME}-math-test math_test.cpp)
target_link_libraries(${PROJECT_NAME}-math-test ${PROJECT_NAME})

add_test(
    NAME math-pow2
    COMMAND $<TARGET_FILE:${PROJECT_NAME}-math-test> pow2
    )
    set_property(
        TEST math-pow2
        PROPERTY LABELS lib math
        )
