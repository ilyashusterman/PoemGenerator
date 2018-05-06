cmake_minimum_required(VERSION 3.10)
project(PoemGenerator)

set(CMAKE_CXX_STANDARD 11)

add_executable(PoemGenerator main.cpp tests/TestPoemGenerator.cpp tests/TestPoemGenerator.h src/PoemGenerator.cpp src/PoemGenerator.h tests/AllTests.cpp tests/AllTests.h)