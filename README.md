# cmake_tutorial (Step 10)
`cmake` commands coulb be often really complex, so we can use `Makefile` to simplify the process. In this step, we will use `Makefile` to rename the commands.

Check this out in [Makefile](Makefile).

Now we can use our own commands to build, test and run the project. 
It's definitely more clear and easier to remember and type.

```bash
make build WOLFRAM_APPID=WGX8JG-KE8XGJW6R7
make test
make run
make clean
```

That's it! We made it!
