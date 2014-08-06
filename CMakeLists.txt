cmake_minimum_required (VERSION 2.8.10)
project (algorithms CXX)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS_INIT} -std=c++11 -Wall -pedantic -Wunreachable-code")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} -O0 -ggdb3")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} -O2")

include_directories(include)

add_executable(runbst run_bst.cpp)
target_link_libraries(runbst)
