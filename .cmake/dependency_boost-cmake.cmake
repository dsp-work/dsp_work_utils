set(BOOST_DISABLE_TESTS OFF CACHE BOOL "build flag of test for boost-cmake" FORCE)
find_package(Boost 1.78.0)
if (boost_FOUND)
  message(STATUS "Boost is found!")
else() # 見つからない場合には自動インストール
  message(STATUS "Boost is not found!")

  option(${PROJECT_NAME}-auto-install-boost "Enable auto installing of boost." ON)
  if(${PROJECT_NAME}-auto-install-boost)
    message(STATUS "Start auto installing boost-cmake...")
    message(STATUS "-- If you want not to install boost-cmake automatically, Configure with `-D${PROJECT_NAME}-auto-install-boost=OFF`.")
    include(FetchContent)
    FetchContent_Declare(
      boost-cmake
      GIT_REPOSITORY https://github.com/chatblanc-ciel/boost-cmake.git
      GIT_TAG master
    )
    FetchContent_MakeAvailable(boost-cmake)
  else()
    message(STATUS "Please install boost your self.")
  endif()

  # TO DO:
  # checking package and reduce redundant build step
  #find_package(boost REQUIRED NO_MODULE)
  #message(STATUS "boost is found!")
endif()