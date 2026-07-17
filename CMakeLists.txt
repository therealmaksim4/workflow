cmake_minimum_required(VERSION 3.16)
project(workflow VERSION 0.0.11 DESCRIPTION "Manage your workflow")

set(CMAKE_CXX_STANDARD_REQUIRED 11)

add_executable(workflow src/main.cpp)

install(TARGETS workflow)
