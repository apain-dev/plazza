cmake_minimum_required(VERSION 3.10)
project(untitled)

INCLUDE_DIRECTORIES(inc)

set(CMAKE_CXX_STANDARD 11)

add_executable(untitled src/slave.cpp inc/slave.hpp src/slave_manager.cpp inc/slave_manager.hpp src/plazza_manager.cpp inc/plazza_manager.hpp src/main.cpp src/parser.cpp inc/parser.hpp)