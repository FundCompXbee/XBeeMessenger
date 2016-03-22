/***********************************
 * Student: Aaron Crawfis
 * netID: acrawfis
 * Date: 15 March 2016
 * Class: CSE 20212 Final Project
 * File: Server.h
 ************************************/

#include "Message.h"

class Server {
public:
    // Constructor & Destructor
    Server();
    Server(int baud, int vb);
    ~Server();
    // Destructor
    void runServer();
private:
    // Data Members
    int serial;
    int baud;
    int command;
    int verbose;
    // Helper Funcitons
    int setupSerial();
    void closeSerial();
    void runCommand();
    void sendMessage(Message *M);
    Message * receiveMessage();
    void logMessage(Message *M);
    void sendNodes();
};