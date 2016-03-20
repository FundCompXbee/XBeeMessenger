/***********************************
 * Student: Aaron Crawfis
 * netID: acrawfis
 * Date: 15 March 2016
 * Class: CSE 20212 Final Project
 * File: Server.h
 ************************************/

class Server {
public:
    // Constructor & Destructor
    Server(int baud);
    ~Server();
    // Destructor
    void runServer();
private:
    // Data Members
    int serial;
    int baud;
    // Helper Funcitons
    void setupSerial();
    void closeSerial();
};