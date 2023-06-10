#[[
Create a configurable variable which could be set by upper CMakeLists or cmake command.

The API ID shouldn't be hard-coded in the source code.
It could be configured by cmake -D.
]]#
set(WOLFRAM_APIID
    ""
    CACHE STRING "WolframAlpha API ID")

if (WOLFRAM_APIID STREQUAL "")
    message(SEND_ERROR "WOLFRAM_APIID should not be empty")
endif()

add_library(libanswer STATIC answer.cpp)
target_include_directories(libanswer PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

#[[
Add WOLFRAM_APIID to the definition list when compiling .cpp files.
So that the API ID could be used in the source code.
]]#
target_compile_definitions(libanswer PRIVATE WOLFRAM_APIID="${WOLFRAM_APIID}")

# Here libcurl should be private for libanswer
target_link_libraries(libanswer PRIVATE wolfram)
