all: main

main: main.o Packet.o
	g++ -o $@ $<

%.o: %.cpp
	g++ -Wall -c -o $@ $^

clean:
	rm -f *.o main
