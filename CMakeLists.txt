# Specify the minimum version of CMake required to build the project.
cmake_minimum_required(VERSION 3.9)
# Set a name to the project.
project(answer)

add_subdirectory(answer)

add_executable(answer_app main.cpp)

# Link the executable to the library.
target_link_libraries(answer_app libanswer)
