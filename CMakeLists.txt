cmake_minimum_required(VERSION 3.16)
project(workflow VERSION 0.1.7 DESCRIPTION "Enhance your coding")

set(CMAKE_CXX_COMPILER g++)
set(CMAKE_CXX_STANDARD_REQUIRED 11)

add_executable(workflow src/main.cpp)

install(TARGETS workflow)
