# cmake_tutorial (Step 2)
In this step, we add more files to the project. 

We just need to add new file to the `objects` variable. 

Also, `make` can automatically generate the dependencies between .o and .cpp, so we can just focus on the head files. You can learn more here in this [Makefile](./Makefile).

---

Type `make all` in the terminal to build the project. You will see the following output.

```bash
D:\Projects\cmake_tutorial\step_2>make all
g++ -c -o main.o main.cpp
g++ -c -o answer.o answer.cpp
g++ -o answer main.o answer.o
```

Now, we can run the executable.

```bash
D:\Projects\cmake_tutorial\step_2>./answer
What is the ultimate answer?
29
Wrong!
What is the ultimate answer?
42
Correct!
```

We can also run the `clean` target to clean the project.

```bash
D:\Projects\cmake_tutorial\step_2>make clean
del -f answer main.o answer.o
```

## Next step
Type `git checkout cmake_03` to start learning cmake!
