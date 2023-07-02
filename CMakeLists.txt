cmake_minimum_required(VERSION 3.25)
project(DicoGenerator)

set(CMAKE_CXX_STANDARD 23)

add_executable(DicoGenerator main.cpp DicoGenerator_Classes.h DicoGenerator_bases_func.h)
