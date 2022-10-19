cmake_minimum_required(VERSION 3.17)
project(myxmlpp)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE SRCS src/*.cpp)
file(GLOB_RECURSE INCS include/*.hpp)

add_library(myxmlpp ${SRCS} ${INCS})
target_include_directories(myxmlpp PUBLIC include)

if (${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_CURRENT_SOURCE_DIR})
    include(FetchContent)
    FetchContent_Declare(
            googletest
            GIT_REPOSITORY https://github.com/google/googletest.git
            GIT_TAG release-1.12.1
    )

    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(googletest)

    enable_testing()

    add_subdirectory(tests)


endif ()