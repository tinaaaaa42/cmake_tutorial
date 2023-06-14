set(WOLFRAM_APIID
    ""
    CACHE STRING "WolframAlpha API ID")

if (WOLFRAM_APIID STREQUAL "")
    message(SEND_ERROR "WOLFRAM_APIID should not be empty")
endif()

add_library(libanswer INTERFACE)
target_include_directories(libanswer
                           INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_compile_definitions(libanswer INTERFACE WOLFRAM_APIID="${WOLFRAM_APIID}")
target_link_libraries(libanswer INTERFACE wolfram)

target_compile_features(libanswer INTERFACE cxx_std_20)


# Only when BUILD_TESTING is on to build the test program
if(BUILD_TESTING)
    add_subdirectory(tests)
endif()