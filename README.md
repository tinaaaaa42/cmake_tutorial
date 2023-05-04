# cmake_tutorial (Step 0)
Let's begin our cmake journey with a simple example. Actually, we will get familiar with `GNU Make` in the beginning steps. First, we will create a simple executable that prints `Hello World!` to the console. 

## Makefile
This is where we define the build rules of command `make`. It's all about dependencies. For example, if we want to build `hello` executable, we need to compile `hello.cpp` first. So, we define a rule for this dependency. 

```makefile
hello: main.cpp
	$(CXX) -o hello main.cpp
	echo "Make hello"
```

Here `$(CXX)` is a variable that holds the compiler name. It's usually `g++` or `clang++`.

Type `make` in the terminal and you will see compiler output and `Make hello` message. 

```bash
D:\Projects\cmake_tutorial\step_0>make
g++ -o hello main.cpp
echo "Make hello"
Make hello
```

Now, we can run the executable.

```bash
D:\Projects\cmake_tutorial\step_0>hello
Hello World!
```

PS: If you are using Windows and MinGW, you may use `mingw32-make` instead.

## Next step
Type `git checkout cmake_01` to learn more about Makefile.
