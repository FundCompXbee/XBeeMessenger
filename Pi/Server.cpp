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

using namespace std;

#define ESCAPE_CHAR         '+'
#define NEW_MESSAGE         'M'
#define OVER                'O'
#define GET_NODES           'N'

// Constructor

Server::Server(int bd, int vb)
{
    // Set variables
    baud = bd;
    verbose = vb;
    
    // Open the serial connection
    setupSerial();
}

// Destructor

Server::~Server()
{
    // Close the serial connection
    closeSerial();
}

/**************************************************
 * Function:
 * Purpose:
 * Inputs:
 * Outputs:
 **************************************************/

void Server::runServer()
{
    // Enter infinite loop
    while(1)
    {
        // Wait for data to be available
        if(serialDataAvail(serial) > 0)
        {
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
}

/**************************************************
 * Function:
 * Purpose:
 * Inputs:
 * Outputs:
 **************************************************/

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
    
    return 0;
}

/**************************************************
 * Function:
 * Purpose:
 * Inputs:
 * Outputs:
 **************************************************/

void Server::closeSerial()
{
    // Close serial instance
    serialClose(serial);
    // Print Message
    if (verbose) cout << "Serial closed" << endl;
}

/**************************************************
 * Function:
 * Purpose:
 * Inputs:
 * Outputs:
 **************************************************/

void Server::runCommand()
{
    // Variables
    Message *M;
    string message;
    
    // Choose what to do based on command
    switch (command)
    {
        case NEW_MESSAGE:
            message = receiveMessage();           // Get Message
            logMessage(message);                  // Log Message
            sendMessage(message);                 // Send Message back out
            
            // Print message
            if (verbose) cout << "MESSAGE RECEIVED" << endl;
            break;
        case GET_NODES:
            sendNodes();                    // Send Nodes
            
            // Print message
            if (verbose) cout << "SENDING NODE INFORMATION" << endl;
            break;
        default:
            // Print message
            if (verbose) cout << "Unknown command" << endl;
            break;
    }
    
}

/**************************************************
 * Function:
 * Purpose:
 * Inputs:
 * Outputs:
 **************************************************/

void Server::sendMessage(string message)
{
    // Send the message
    serialPuts(serial, message);
    
    // Print message
    if (verbose) cout << "Sending message" << endl;
}

/**************************************************
 * Function:
 * Purpose:
 * Inputs:
 * Outputs:
 **************************************************/

string Server::receiveMessage()
{
    // Variables
    char temp;
    bool keepReading = true;
    string inJSON = "";
    
    // Create new message
    Message *M = new Message;
    
    while (true)
    {
        // Read from serial
        temp = serialGetchar(serial);
        
        // Escape character received
        if (temp == ESCAPE_CHAR)
        {
            temp = serialGetchar(serial);
            if (temp == OVER) break;
        }
        
        // Append to string
        inJSON += temp;
    }
    
    // Print status message
    if (verbose) cout << "Message Received" << endl;
    // Return the message
    return inJSON;
}

/**************************************************
 * Function:
 * Purpose:
 * Inputs:
 * Outputs:
 **************************************************/

void Server::logMessage(string message)
{
    
    // Print message
    if (verbose) cout << "Message Logged" << endl;
}

/**************************************************
 * Function:
 * Purpose:
 * Inputs:
 * Outputs:
 **************************************************/

int Server::pollDevices()
{
    
}

