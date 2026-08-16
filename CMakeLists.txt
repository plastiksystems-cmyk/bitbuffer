cmake_minimum_required(VERSION 4.2.3)

project(bitbuffer_tests)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(bitbuffer_tests "tests/test4.cxx")
target_include_directories(bitbuffer_tests PRIVATE "${PROJECT_SOURCE_DIR}/include/bitbuffer")