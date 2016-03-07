#Name: Conrad Bailey
#Course: Fundamentals of Computing II
#Purpose: Makefile - Rules for compiling all parts of the project

EXE=testEnv.exe
OBJS=testEnv.o tui.o window.o

CXX=g++
CXXFLAGS=-W -Wall -Wextra -Werror -std=gnu++11

LINKER=g++
LINKERFLAGS=-std=gnu++11
LINKS=-lncurses -ljsoncpp

all: $(OBJS) $(EXE)

# Link objects into the executable
%.exe: $(OBJS)
	$(LINKER) $(LINKERFLAGS) $(LINKS) $(OBJS) -o $@

# Compile an object file
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f *.exe *.o
