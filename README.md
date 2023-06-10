# cmake_tutorial (Step 7)
As said brfore, the api id should not be hard coded in the source code. If we want to specify it in the compiling process, we can use `CATHE` string to do that.

Changes are all made in [answer](answer) folder.

To add a `CATHE` string, we need to add these lines in [CMakeLists.txt](answer/CMakeLists.txt):

```cmake
set(WOLFRAM_APIID                       # the name of the variable
    ""                                  # the default value
    CACHE STRING "WolframAlpha API ID") # Type and description
```

After we add it to the definition list, we can use it in .cpp files as a macro.

---
To specify the `CATHE` string, we can use `-D` option in `cmake` command:

```bash
cmake -B build -DWOLFRAM_APIID=WGX8JG-KE8XGJW6R7
```

Or we can use `ccmake` to change the value of `WOLFRAM_APIID` in the GUI:

```bash
ccmake -B build
```

Then we can build and run the project as before:
```bash
cmake --build build # build the project
./build/answer_app  # run the project
```

## Next step
Type `git checkout cmake_08` to learn more about cmake.
