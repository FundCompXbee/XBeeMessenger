/***********************************
* Student: Aaron Crawfis
* netID: acrawfis
* Date: 15 March 2016
* Class: CSE 20212 Final Project
* File: piServer.c
************************************/

#include <stdlib.h>
#include <stdio.h>
#include <wiringSerial.h>

void runServer(int serial);

int main()
{
	// Print welcome message
	printf("piServer starting...\n");

	// Setup Serial Interface
	int fd = serialOpen("/dev/ttyAMA0",38400);

	// Check for opening error
	if (fd < 0)
	{
		printf("Error opening serial interface\n");
		return EXIT_FAILURE;
	}
	else printf("Serial interface successfully opened\n");

	// Run server
	runServer(fd);

	// It shoudld never reach this point.
	return EXIT_SUCCESS;
}

void runServer(int serial)
{

}

