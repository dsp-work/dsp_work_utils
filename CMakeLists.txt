cmake_minimum_required(VERSION 3.16)

# project name
project(dsp_work_utils CXX)

#--------------- CMake compile config ------------------------------
include(./.cmake/cxx_config.cmake)

#----------------- clang-format config -------------------------
include(./.cmake/clang-format.cmake)

# ---------- dependencies ----------
include(./.cmake/dependency_boost-cmake.cmake)


#------------------ build source config ------------------

# libraries
add_library(${PROJECT_NAME} INTERFACE)
  target_link_libraries(${PROJECT_NAME} INTERFACE Boost::boost)
  # depends from stack backtrace
  target_link_libraries(${PROJECT_NAME} INTERFACE ${CMAKE_DL_LIBS})


# include path
target_include_directories(${PROJECT_NAME} INTERFACE utils)

# Imported target support
add_library (${PROJECT_NAME}::utils ALIAS ${PROJECT_NAME})
target_include_directories (${PROJECT_NAME} INTERFACE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:${INCLUDE_INSTALL_DIR}>
)

# The dsp_work_utils target will be located in the DspWork namespace. Other CMake
# targets can refer to it using DspWork::Utils.
export (TARGETS ${PROJECT_NAME} NAMESPACE ${PROJECT_NAME}:: FILE ${PROJECT_NAME}Targets.cmake)
# Export dsp_work_utils package to CMake registry such that it can be easily found by
# CMake even if it has not been installed to a standard directory.
export (PACKAGE ${PROJECT_NAME})

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
  include(CTest)
  add_subdirectory(test)
endif()
