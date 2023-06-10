# cmake_tutorial (Step 3)
Here we bagin learning cmake!
First of all, why use cmake?
An important reason is that make is usually limited to one folder. That's not how we build a large project.

The simplest CMakeLists.txt should have this 3 lines, as you can see in the [CMakeLists.txt](./CMakeLists.txt).
```cmake
cmake_minimum_required(VERSION 3.9)
project(answer)
add_executable(answer main.cpp answer.cpp)
```

---
The command of cmake is a little different from make.

Type `cmake -B build` to add a folder named `build` to store the build files.

```bash
cmake -B build      # add a folder named build to store the build files
cmake --build build # build the project
./build/answer      # run the project
```

If the default generator of cmake is VS on your computer, there would be a lot of stuff in `build` folder and the executable file is in `build/Debug` folder.

## Next step
Type `git checkout cmake_04` to learn more about cmake.
