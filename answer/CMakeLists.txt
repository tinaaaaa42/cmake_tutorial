add_library(libanswer STATIC answer.cpp)

#[[
Use meesage to print debug message, like STSTUS,
DEBUG ERROR WARNING
#]]
message(STATUS "Current source dir: ${CMAKE_CURRENT_SOURCE_DIR}")

#[[
Add include directory to the libanswer target.
PUBLIC makes the include directory visible to outside users.

When linking libanswer to the executable, the include directory
will be added to the include path automatically.
#]]
target_include_directories(libanswer PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
