cmake_minimum_required(VERSION 3.21)
project(brainfuck_for_embedded)

set(CMAKE_CXX_STANDARD 17)

add_executable(brainfuck_for_embedded main.cpp parser.cpp parser.h execute.cpp execute.h)
