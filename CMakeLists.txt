# Specify the minimum version of CMake required to build the project.
cmake_minimum_required(VERSION 3.9)
# Set a name to the project.
project(answer)

#[[
Add an executable(target) to the project using the specified source files.

    answer: main.o answer.o
    main.o: main.cpp answer.hpp
    answer.o: answer.cpp answer.hpp

CMake will automatically find the dependencies of the head files.
#]]
add_executable(answer main.cpp answer.cpp)
