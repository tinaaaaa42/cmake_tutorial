# Specify the minimum version of CMake required to build the project.
cmake_minimum_required(VERSION 3.0)
# Set a name to the project.
# set(CMAKE_TOOLCHAIN_FILE "D:/vcpkg/vcpkg/scripts/buildsystems/vcpkg.cmake")
project(answer)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(answer)

add_executable(answer_app main.cpp)

# Link the executable to the library.
target_link_libraries(answer_app libanswer)
