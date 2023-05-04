# cmake_tutorial (Step 1)
In this step, we add variables in Makefile to make it more flexible. 

The syntax of defining a variable:
```makefile
VARIABLE_NAME := value
```

We often use variables to specify the default compiler, compiler flags, and so on. You can learn the basic here in this [Makefile](./Makefile).

---

Type `make` in the terminal to build the project. You will see the following output.

```bash
D:\Projects\cmake_tutorial\step_0>make
g++ -c main.cpp
g++ -o hello main.cpp
```

Now, we can run the executable.

```bash
D:\Projects\cmake_tutorial\step_0>./hello
Hello, World!
```

We can also run the `clean` target to clean the project.

```bash
D:\Projects\cmake_tutorial\step_0>make clean
del -f *.o hello
```

PS: The `del` command is for Windows. If you are using Linux, you can use `rm` instead.

## Next step
Type `git checkout cmake_02` to learn more about Makefile.
