

EXE=testJSON.exe
OBJS=testJSON.o

CXX=g++
XFLAGS=-W -Wall -Wextra -Werror 

LINKER=g++
LINKERFLAGS=-std=gnu++11
LINKS=-ljsoncpp

all: $(OBJS) $(EXE)

%.exe: $(OBJS)
	$(LINKER) $(LINKERFLAGS) $(LINKS) $(OBJS) -o $@ 

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f *.o main
