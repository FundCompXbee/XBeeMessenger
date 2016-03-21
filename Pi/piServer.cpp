/***********************************
* Student: Aaron Crawfis
* netID: acrawfis
* Date: 15 March 2016
* Class: CSE 20212 Final Project
* File: piServer.cpp
************************************/

#include <iostream>
#include "Server.h"

using namespace std;

#define BAUD_RATE 38400

int main()
{
    // Create Server
    cout << "Opening Pi Server" << endl;
    Server s(BAUD_RATE, 1);
    
    // Run Server
    cout << "Running Pi Server" << endl;
    s.runServer();
}