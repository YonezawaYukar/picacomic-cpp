cmake_minimum_required(VERSION 3.22)
project(untitled)

set(CMAKE_CXX_STANDARD 20)
add_executable(untitled example.cpp hmacsha256.h GenerateSignature.cpp GenerateSignature.h)
target_link_libraries(untitled crypto++)