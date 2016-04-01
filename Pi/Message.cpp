/**********************************
 * Student: Aaron Crawfis
 * netID: acrawfis
	  jdiazort
 * Date: 1 March 2016
 * Class: CSE 20212 Final Project
 * File: Message.cpp
 ************************************/

#include "Message.h"
#include "/usr/include/jsoncpp/json/json.h"

Message::Message()
	:Packet()
{
    messageContent = "";
    setField("content",messageContent);  
}

Message::Message(string msg)
	:Packet()
{
    messageContent = msg;
    setField("content",messageContent);
}

/*
void Message::packageMessageIntoJSON()
{
    
}
*/

void Message::setMessage(string val)
{
    messageContent = val;
    setField("content",messageContent);
}

string Message::getMessage()
{
    return messageContent;
}
