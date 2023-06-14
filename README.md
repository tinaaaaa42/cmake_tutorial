# cmake_tutorial (Step 9)
In this step, we try to add test to our project. 

## CTest
To use `CTest`, we need to add the following lines to our `CMakeLists.txt`:

```cmake
# CMakeLists.txt
cmake_minimum_required(VERSION 3.14) # 提高了 CMake 版本要求
project(answer)

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    include(CTest)
endif()
```
```cmake
# answer/CMakeLists.txt
if(BUILD_TESTING)
    add_subdirectory(tests)
endif()
```
```cmake
# answer/tests/CMakeLists.txt
add_executable(test_some_func test_some_func.cpp)
add_test(NAME answer.test_some_func COMMAND test_some_func)
```
You can check [CMakeLists.txt](./CMakeLists.txt), [answer/CMakeLists.txt](./answer/CMakeLists.txt) and [answer/tests/CMakeLists.txt](./answer/tests/CMakeLists.txt) for more details.

## FetchContent
Besides `find_package`, we can also use `FetchContent` to download and build a project. For example, we can use `FetchContent` to download and build `Catch2`. Check it in [answer/tests/CMakeLists.txt](./answer/tests/CMakeLists.txt).

PS: we need to download and build the package, so it will take more time when we generate the `build` folder and build the project.

## Macro and Function
When we would repeat a certain piece of codes, we can use `macro` or `function` to simplify our `CMakeLists.txt`. For example, we can use `macro` to simplify the `add_test` command. 

```cmake
macro(answer_add_test TEST_NAME)
    add_executable(${TEST_NAME} ${ARGN}) # ${ARGN} 类似于 C/C++ 中的 __VA_ARGS__
    add_test(NAME answer.${TEST_NAME} COMMAND ${TEST_NAME})
    target_link_libraries(${TEST_NAME} PRIVATE libanswer)
    target_link_libraries(${TEST_NAME} PRIVATE Catch2::Catch2WithMain)
endmacro()

answer_add_test(test_check_the_answer test_check_the_answer.cpp)
answer_add_test(test_another_function test_another_function.cpp)
```

These concepts are similar to C/C++. Check it in [answer/tests/CMakeLists.txt](./answer/tests/CMakeLists.txt).

---
You can build and run the program like step7. And we can run the test programs like this:

```bash
cmake -B build -DWOLFRAM_APIID=WGX8JG-KE8XGJW6R7
cmake --build build                  # build the project
ctest --test-dir build -R "^answer." # run the tests
./build/answer_app                   # run the project
```

## Next step
Type `git checkout cmake_10` to move to our last step.
