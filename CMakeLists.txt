cmake_minimum_required(VERSION 3.20)
project(Sha256)

set(CMAKE_CXX_STANDARD 23)

add_executable(Sha256 main.cpp picosha2.h)
