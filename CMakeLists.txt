cmake_minimum_required(VERSION 3.14)  # higher version
project(answer)

#[[
To judge whether the current directory is the top-level called by CMake, if it is,
introduce CTest support.

This will introduce a BUILD_TESTING option (similar to the previous CACHE
STRING, this is a CACHE BOOL), whose default value is ON,
you can decide whether to include it in the subsequent CMake script.
#]]
if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    include(CTest)
endif()

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(answer)
add_subdirectory(curl_wrapper)
add_subdirectory(wolfram)

add_executable(answer_app main.cpp)
target_link_libraries(answer_app libanswer)
