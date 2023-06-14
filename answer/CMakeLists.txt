set(WOLFRAM_APIID
    ""
    CACHE STRING "WolframAlpha API ID")

if (WOLFRAM_APIID STREQUAL "")
    message(SEND_ERROR "WOLFRAM_APIID should not be empty")
endif()


#[[
target of INTERFACE are usually used when there are no source files,
such as header-only libraries, or just to abstractly provide a set of
target_xxx configurations.

INTERFACE target can be used as a dependency of other targets, and
the target_xxx configurations should also be INTERFACE.

Here we change libanswer from STATIC target to INTERFACE target, but 
it won't affect the code in answer_app which uses it.
#]]
add_library(libanswer INTERFACE)
target_include_directories(libanswer
                           INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_compile_definitions(libanswer INTERFACE WOLFRAM_APIID="${WOLFRAM_APIID}")
target_link_libraries(libanswer INTERFACE wolfram)

#[[
Specify libanswer with C++20 standard.
#]]
target_compile_features(libanswer INTERFACE cxx_std_20)
