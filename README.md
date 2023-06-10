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
\home\user\cmake_tutorial > make
g++ -c main.cpp
g++ -o hello main.cpp
```

Now, we can run the executable.

```bash
\home\user\cmake_tutorial > ./hello
Hello, World!
```

We can also run the `clean` target to clean the project.

```bash
\home\user\cmake_tutorial > make clean
rm -f *.o hello
```

PS: The `rm` command is for Linux. If you are using Windows, you can use `del` instead.

## Next step
Type `git checkout cmake_02` to learn more about Makefile.
