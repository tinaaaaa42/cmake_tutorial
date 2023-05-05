# cmake_tutorial (Step 5)
In this step, we make our answer files more complicated, calling wolframalpha api to get the answer.

## vcpkg
Here we use [vcpkg](https://vcpkg.io/en/getting-started.html) to install the library we need.

If you are using Windows, it's better to use **Powershell** to install vcpkg.
If you are using VSCode, you should do more things to make it work. 
```bash
git clone https://github.com/Microsoft/vcpkg.git
.\vcpkg\bootstrap-vcpkg.bat
vcpkg install curl  # pay attention to the version
# move to your project folder
vcpkg integrate install
vcpkg integrate project
```

Additionally, you should configure the `CMakeLists.txt` file to make it work. And there are 3 ways to do it.

- Add the following lines to the `CMakeLists.txt` file
```cmake
set(CMAKE_TOOLCHAIN_FILE "path/to/vcpkg/scripts/buildsystems/vcpkg.cmake")
```
- Create a file named 'settings.json' in .vscode folder, and add the following lines to the file
```json
{
    "cmake.configureSettings": {
        "CMAKE_TOOLCHAIN_FILE": "path/to/vcpkg/scripts/buildsystems/vcpkg.cmake"
    }
}
```
- Open the setting of VSCode, click the json botton on the right top side and add the following lines to the file
```json
"CMakeToolchainFile": "path/to/vcpkg/scripts/buildsystems/vcpkg.cmake"
```

Then you can use `#include <curl/curl.h>` in your code.

## Add the library to the project
Add the following lines to the `CMakeLists.txt` file
```cmake
find_package(CURL CONFIG REQUIRED)
target_link_libraries(answer PRIVATE CURL::libcurl)
```
As you can see in the [answer/CMakeLists.txt](answer/CMakeLists.txt) file.

---
The command is the same as step 3:

```bash
cmake -B build # add a folder named build to store the build files
cmake --build build # build the project
./build/answer # run the project
```

## Next step
You may think it's dumb to use api id straightly in the code, and it's way too much in the single function 'expected_answer'.
Type `git checkout cmake_06` to learn more about cmake.
