# use CC and CXX to specify the compiler
CC := gcc
CXX := g++

.PHONY: all
all: answer

# Since main.o might be used more than once, we use a variable to store it
objects := main.o answer.o

# $@ means the target
answer: $(objects)
	$(CXX) -o $@ $(objects)

# Actually, Make can automatically find the dependency of
# a .o file with .cpp file of the same name.

# So we can just specify the head file dependency
main.o: answer.hpp
answer.o: answer.hpp

# .PHONY is used to specify the target is not a file
.PHONY: clean
clean:
	del -f answer $(objects)  # del is used in Windows
                            # rm is used in Linux