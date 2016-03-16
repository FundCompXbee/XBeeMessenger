all: pi client

pi: Pi/piServer.c
	gcc -Wall piServer.c -o piServer

client:
	echo "No client config yet"

clean:
	rm piServer
