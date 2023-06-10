# use CC and CXX to specify the compiler
CC := gcc
CXX := g++

# Since main.o might be used more than once, we use a variable to store it
object := main.o

# $@ means the target
hello: $(object)
	$(CXX) -o $@ $(object)

main.o: main.cpp
	$(CXX) -c main.cpp

# .PHONY is used to specify the target is not a file
.PHONY: clean
clean:
	rm -f hello $(object)   # rm is used in Linux
                            # del is used in Windows