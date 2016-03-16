all: pi client

pi: Pi/piServer.c
	gcc -Wall Pi/piServer.c -o Pi/piServer -lwiringPi

client:
	echo "No client config yet"

clean:
	rm Pi/piServer
