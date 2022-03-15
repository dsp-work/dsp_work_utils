cmake_minimum_required(VERSION 3.16)

add_executable(${PROJECT_NAME}-file_operation-test file_operation_test.cpp)
target_link_libraries(${PROJECT_NAME}-file_operation-test ${PROJECT_NAME})

# prepared necessary files for test
add_custom_command(
    TARGET ${PROJECT_NAME}-file_operation-test
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E
        copy ${CMAKE_CURRENT_SOURCE_DIR}/test_data.txt
            $<TARGET_FILE_DIR:${PROJECT_NAME}-file_operation-test>)
add_custom_command(
    TARGET ${PROJECT_NAME}-file_operation-test
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E
        copy ${CMAKE_CURRENT_SOURCE_DIR}/test.dat
            $<TARGET_FILE_DIR:${PROJECT_NAME}-file_operation-test>)
add_custom_command(
    TARGET ${PROJECT_NAME}-file_operation-test
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E
        copy ${CMAKE_CURRENT_SOURCE_DIR}/test.wav
            $<TARGET_FILE_DIR:${PROJECT_NAME}-file_operation-test>)


# add test
add_test(
    NAME file_operation-fileopen
    COMMAND $<TARGET_FILE:${PROJECT_NAME}-file_operation-test> fileopen
    )
    set_property(
        TEST file_operation-fileopen
        PROPERTY LABELS lib file_operation stdlib_operation
        )

add_test(
    NAME file_operation-file_size
    COMMAND $<TARGET_FILE:${PROJECT_NAME}-file_operation-test> file_size
    )
    set_property(
        TEST file_operation-file_size
        PROPERTY LABELS lib file_operation stdlib_operation
        )