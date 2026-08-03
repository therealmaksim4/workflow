cmake_minimum_required(VERSION 3.16)
project(workflow VERSION 0.2.0 DESCRIPTION "Enhance your coding")

set(CMAKE_CXX_COMPILER g++)
set(CMAKE_CXX_STANDARD_REQUIRED 11)

add_executable(workflow src/main.cpp)

install(TARGETS workflow)
