cmake_minimum_required(VERSION 3.16)

add_executable(${PROJECT_NAME}-file-test file_test.cpp)
target_link_libraries(${PROJECT_NAME}-file-test ${PROJECT_NAME})

# prepared necessary files for test
add_custom_command(
    TARGET ${PROJECT_NAME}-file-test
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E
        copy ${CMAKE_CURRENT_SOURCE_DIR}/test_data.txt
            $<TARGET_FILE_DIR:${PROJECT_NAME}-file-test>)
add_custom_command(
    TARGET ${PROJECT_NAME}-file-test
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E
        copy ${CMAKE_CURRENT_SOURCE_DIR}/test.dat
            $<TARGET_FILE_DIR:${PROJECT_NAME}-file-test>)
add_custom_command(
    TARGET ${PROJECT_NAME}-file-test
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E
        copy ${CMAKE_CURRENT_SOURCE_DIR}/test.wav
            $<TARGET_FILE_DIR:${PROJECT_NAME}-file-test>)


# add test
add_test(
    NAME file-fileopen
    COMMAND $<TARGET_FILE:${PROJECT_NAME}-file-test> fileopen
    )
    set_property(
        TEST file-fileopen
        PROPERTY LABELS lib file stdlib
        )

add_test(
    NAME file-file_size
    COMMAND $<TARGET_FILE:${PROJECT_NAME}-file-test> file_size
    )
    set_property(
        TEST file-file_size
        PROPERTY LABELS lib file stdlib
        )