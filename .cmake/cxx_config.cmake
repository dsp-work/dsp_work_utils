enable_language(CXX)
set(CMAKE_CXX_STANDARD 11) # C++11
set(CMAKE_CXX_STANDARD_REQUIRED ON) #...is required...

if(MSVC)
    message(STATUS "using MSVC compiler, set compile flag for msvc")
    set(CMAKE_CXX_FLAGS "-Wall /W4 /Zi /EHsc")
    set(CMAKE_CXX_FLAGS_DEBUG "/Od /DEBUG:FULL -march=native")
    set(CMAKE_CXX_FLAGS_RELEASE "-DNDEBUG -O3 /O2")
    set(CMAKE_CXX_FLAGS_MINSIZEREL "-Os -DNDEBUG -march=native")
    set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-O3 /O2 /DEBUG:FULL -march=native")
    
elseif(CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
    message(STATUS "using GNU compiler, set compile flag for gnu")
    set(CMAKE_CXX_FLAGS "-Wall -pg -pedantic -Wcast-align -Wcast-qual -Wconversion -Wdisabled-optimization -Wendif-labels -Wfloat-equal -Winit-self -Winline -Wmissing-include-dirs -Wnon-virtual-dtor -Wold-style-cast -Woverloaded-virtual -Wpacked -Wpointer-arith -Wredundant-decls -Wshadow -Wsign-promo -Wswitch-default -Wswitch-enum -Wvariadic-macros -Wwrite-strings ")
    set(CMAKE_CXX_FLAGS_DEBUG "-g3 -O0")
    set(CMAKE_CXX_FLAGS_RELEASE "-g3 -O3 -DNDEBUG -march=native")
    set(CMAKE_CXX_FLAGS_MINSIZEREL "-Os -DNDEBUG -march=native")
    set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-g3 -Og -march=native")

endif()