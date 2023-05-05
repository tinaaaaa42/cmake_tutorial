#[[
Use find_package to find the package installed on the system.
#]]
find_package(CURL REQUIRED)

add_library(libanswer STATIC answer.cpp)

#[[
Add include directory to the libanswer target.
PUBLIC makes the include directory visible to outside users.

When linking libanswer to the executable, the include directory
will be added to the include path automatically.
#]]
target_include_directories(libanswer PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Here libcurl should be private for libanswer
target_link_libraries(libanswer PRIVATE CURL::libcurl)
