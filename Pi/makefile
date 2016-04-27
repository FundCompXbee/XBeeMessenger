CLIENTEXE=XBeeClient.exe
CLIENTOBJS=XBeeClient.o serial.o envelope.o client.o

SERVEREXE=XBeeServer.exe
SERVEROBJS=XBeeServer.o server.o IRCCommandHandler.o serial.o envelope.o user.o channel.o

CXX=g++ -std=gnu++11
CXXFLAGS=-03

LINKER=g++
LINKERFLAGS=-std=gnu++11
LINKS=-ljsoncpp -lboost_system -lpthread

all: $(CLIENTEXE) $(SERVEREXE)

debug: CXXFLAGS=-W -Wall -Wextra -Werror -O0 -ggdb3
debug: all

$(CLIENTEXE): $(CLIENTOBJS)
	$(LINKER) $(LINKERFLAGS) $(LINKS) $(CLIENTOBJS) -o $@

$(SERVEREXE): $(SERVEROBJS)
	$(LINKER) $(LINKERFLAGS) $(LINKS) $(SERVEROBJS) -o $@

envelope.o: envelope.cpp envelope.hpp
	$(CXX) $(CXXFLAGS) -c $<

serial.o: serial.cpp serial.hpp
	$(CXX) $(CXXFLAGS) -c $<

user.o: user.cpp user.hpp
	$(CXX) $(CXXFLAGS) -c $<

channel.o: channel.cpp channel.hpp user.o
	$(CXX) $(CXXFLAGS) -c $<

IRCCommandHandler.o: IRCCommandHandler.cpp IRCCommandHandler.hpp channel.o user.o
	$(CXX) $(CXXFLAGS) -c $<

server.o: server.cpp server.hpp IRCCommandHandler.o serial.o envelope.o
	$(CXX) $(CXXFLAGS) -c $<

client.o: client.cpp client.hpp serial.o envelope.o
	$(CXX) $(CXXFLAGS) -c $<

XBeeClient.o: XBeeClient.cpp client.o
	$(CXX) $(CXXFLAGS) -c $<

XBeeServer.o: XBeeServer.cpp server.o
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f *.o *.exe
