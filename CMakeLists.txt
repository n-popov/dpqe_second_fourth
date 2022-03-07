cmake_minimum_required(VERSION 3.20)
project(dpqe_second_fourth)

set(CMAKE_CXX_STANDARD 20)

add_executable(main filesystem.cpp)
add_executable(banana bananas.cpp)
add_executable(map translation.cpp)
add_executable(search regex.cpp)
