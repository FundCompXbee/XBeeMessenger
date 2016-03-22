/***********************************
 * Student: Aaron Crawfis
 * netID: acrawfis
 * Date: 15 March 2016
 * Class: CSE 20212 Final Project
 * File: Message.h
 ************************************/

#include "Packet.h"

class Message: public Packet
{
public:
    // Constructors
    Message();
    Message(string mesg);
    
    // Member Functions
    void packageMessageIntoJSON();
private:
    // Data Members
    string messageContent;
};