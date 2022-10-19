cmake_minimum_required(VERSION 3.17)
project(myxmlpp)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE UNIT_TESTS_SRCS unit-testing/*.cpp)
get_target_property(MYXMLPP_INCLUDE_DIRS myxmlpp INCLUDE_DIRECTORIES)

add_executable(myxmlppexec EXCLUDE_FROM_ALL test.cpp)
target_link_libraries(myxmlppexec PRIVATE myxmlpp)
target_include_directories(myxmlppexec PRIVATE ${MYXMLPP_INCLUDE_DIRS})

add_executable(unit-tests EXCLUDE_FROM_ALL ${UNIT_TESTS_SRCS})
target_link_libraries(unit-tests PRIVATE myxmlpp GTest::gtest_main)
target_include_directories(unit-tests PRIVATE ${MYXMLPP_INCLUDE_DIRS})

include(GoogleTest)
gtest_discover_tests(unit-tests)