CC=		g++
CFLAGS=		-c
TARGETS=	pi client
PITARGETS=	Pi/piServer.o Pi/Server.o Pi/Message.o Pi/Packet.o

all: $(TARGETS)

pi: piServer.o Server.o Message.o Packet.o
	$(CC) Pi/piServer.o Pi/Server.o -lwiringPi

client:
	echo "No client config yet"

%.o: %.c
	$(CC) $(CFLAGS) $<

clean:
	rm $(PITARGETS)
