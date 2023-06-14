# import FetchContent commands
include(FetchContent)

# describehow to get Catch2
FetchContent_Declare(
    catch2 # lower letters
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v3.3.2)

# download and build Catch2
FetchContent_MakeAvailable(catch2)

#[[
FetchContent requires CMake 3.11 or later. 
You can also use Git submodules + add_subdirectory to use third-party libraries.

FetchContent_MakeAvailable requires CMake 3.14 or later.
If you need a older version or more fine-grained control,
you can use the following instead:

    FetchContent_GetProperties(catch2)
    if(NOT catch2_POPULATED)
        FetchContent_Populate(catch2)
        add_subdirectory(${catch2_SOURCE_DIR} ${catch2_BINARY_DIR})
    endif()
#]]

# macro is similar to the macro in C/C++
macro(answer_add_test TEST_NAME)
    add_executable(${TEST_NAME} ${ARGN}) # ${ARGN} is similar to __VA_ARGS__ in C/C++
    #[[
    Use add_test to add test programs that CTest can see.
    It's recommended to use a prefix of the project name to make it 
    convenient to distinguish from other third-party libraries.
    #]]
    add_test(NAME answer.${TEST_NAME} COMMAND ${TEST_NAME})
    target_link_libraries(${TEST_NAME} PRIVATE libanswer)
    #[[
    Link Catch2::Catch2WithMain to use the macro that Catch2 provides.
    When linking Catch2WithMain，there is no need to write main function in the test program.
    #]]
    target_link_libraries(${TEST_NAME} PRIVATE Catch2::Catch2WithMain)
endmacro()

# Call the above macro to add test programs
answer_add_test(test_check_the_answer test_check_the_answer.cpp)