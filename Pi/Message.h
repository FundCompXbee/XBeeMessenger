/***********************************
 * Student: Aaron Crawfis
 * netID: acrawfis
	  jdiazort
 * Date: 1 April 2016
 * Class: CSE 20212 Final Project
 * File: Message.h
 ************************************/
#ifndef MESSAGE_H
#define MESSAGE_H

#include "Packet.h"
#include <string>

class Message: public Packet
{
  public:
    // Constructors
    Message();
    Message(string msg);
    
    // Member Functions
    void setMessage(string val);
    string getMessage();
    void packageMessageIntoJSON();
  private:
    // Data Members
    string messageContent;    
};

#endif
