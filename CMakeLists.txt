cmake_minimum_required(VERSION 3.16)
project(code)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-O3 -Wall")

add_executable(code main.cpp)