# cmake_tutorial (Step 8)
Now the project is actually in nice design. We try to modify some details to introduce more on `cmake`.

## INTERFACE
We can use `INTERFACE` to define the interface of a library, which is usually header-only. For more details, see in this [answer/CMakeLists.txt](./answer/CMakeLists.txt).

## Standard features
We can use `target_compile_features` to specify the standard features we want to use, as in this [answer/CMakeLists.txt](./answer/CMakeLists.txt).

It's different from `CMAKE_CXX_STANDARD`, which can affect all targets. `target_compile_features` can only affect the specified target.

And `target_compile_features` can be more detailed, like `cxx_auto_type` and `cxx_lambda`.

---
Build and run the project like step07:

```bash
cmake -B build -DWOLFRAM_APIID=WGX8JG-KE8XGJW6R7
cmake --build build # build the project
./build/answer_app  # run the project
```

## Next step
Type `git checkout cmake_09` to learn more about cmake.
