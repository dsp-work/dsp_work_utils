cmake_minimum_required(VERSION 3.16)

# project name
project(dsp_work_utils CXX)

#--------------- CMake compile config ------------------------------
include(./.cmake/cxx_config.cmake)

#----------------- clang-format config -------------------------
include(./.cmake/clang-format.cmake)

#------------------ build source config ------------------

# libraries
add_library(${PROJECT_NAME} INTERFACE)

# include path
target_include_directories(${PROJECT_NAME} INTERFACE utils)

# Imported target support
add_library (DspWork::Utils ALIAS ${PROJECT_NAME})
target_include_directories (${PROJECT_NAME} INTERFACE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:${INCLUDE_INSTALL_DIR}>
)

# for development executable(optional activate)
option(DEVELOP_EXECUTABLE_${PROJECT_NAME} "Build develop executable file on ${PROJECT_NAME} package" OFF)
if(DEVELOP_EXECUTABLE_${PROJECT_NAME})
# executables
    add_executable(develop_main develop_main.cpp)
    target_link_libraries(develop_main ${PROJECT_NAME})
endif()

# tests
option(${PROJECT_NAME}-with-test "Enable creation of tests." ON)
if(${PROJECT_NAME}-with-test)
  enable_testing()
  add_subdirectory(test)
endif()
