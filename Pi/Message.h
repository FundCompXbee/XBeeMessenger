/***********************************
 * Student: Aaron Crawfis
 * netID: acrawfis
 * Date: 15 March 2016
 * Class: CSE 20212 Final Project
 * File: Message.h
 ************************************/

#include "Packet.h"
#include <string>

class Message: public Packet
{
public:
    // Constructors
    Message();
    Message(string mesg);
    
    // Member Functions
    void setMessage(string val);
    string getMessage();
    void packageMessageIntoJSON();
private:
    // Data Members
    string messageContent;
};