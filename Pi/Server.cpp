/***********************************
 * Student: Aaron Crawfis
 * netID: acrawfis
 * Date: 15 March 2016
 * Class: CSE 20212 Final Project
 * File: Server.cpp
 ************************************/

#include <iostream>
#include "Server.h"
#include <wiringSerial.h>

#define ESCAPE_CHAR         '+'
#define NEW_MESSAGE         'M'
#define OVER                'O'
#define GET_NODES           'N'

Server::Server(int baud)
{
    setupSerial()
}

Server::~Server()
{
    closeSerial();
}

/**********************************************/

void Server::runServer()
{
    // Enter infinite loop
    while(1)
    {
        // Wait for data to be available
        while(serialDataAvail(serial) == 0);
        
        // Check if the escape character is available
        if (serialGetchar(serial) == ESCAPE_CHAR)
        {
            // Get the command
            command = serialGetchar(serial);
            // Run the command
            if (verbose) cout << "Running command: " << command << endl;
            runCommand();
        }
        // Bad character. Loop around
        else
        {
            if (verbose) cout << "Bad character" << endl;
            continue;
        }
    }
}

/**********************************************/

int Server::setupSerial()
{
    // Create serial instance
    serial = serialOpen("/dev/ttyAMA0", baud);
    // Check for opening error
    if (serial < 0)
    {
        cout << "Error opening serial port" << endl;
        return 1;
    }
}

void Server::closeSerial()
{
    // Close serial instance
    serialClose(serial);
}

void runCommand()
{
    // Choose what to do based on command
    switch (command)
    {
        case NEW_MESSAGE:
            // Convert buffer to string
            // Convert string to JSON object
            // Convert JSON object to message object
            // Save Message Object
            // Send Message to all clients
            break;
        case GET_NODES:
            // Gather & package nodes
            // Send nodes
            break;
        default:
            cout << "Unknown command" << endl;
            break;
    }
}

