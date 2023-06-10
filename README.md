# cmake_tutorial (Step 4)
In this step, we add a library and subdirectory to the project to make the structure more clear.
Notice that there will be two CMakelists.txt files in the project.

In the root file, the main project uses the library in the subdirectory with this 2 lines:
```cmake
add_subdirectory(answer)
target_link_libraries(answer_app libanswer)
```

In the subdirectory, the library is built with this 2 lines:
```cmake
add_library(libanswer answer.cpp)
target_include_directories(libanswer PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
```
Remember to add `PUBLIC` to make the header file visible to the main project.

You can find the root [CMakeLists.txt](./CMakeLists.txt) and [answer/CMakeLists.txt](./answer/CMakeLists.txt) here.

---
The command is the same as step 3:

```bash
cmake -B build      # add a folder named build to store the build files
cmake --build build # build the project
./build/answer_app  # run the project
```

## Next step
Type `git checkout cmake_05` to learn more about cmake.
