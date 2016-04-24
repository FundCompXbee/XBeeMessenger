/***********************************
 * Student: Aaron Crawfis
 * netID: acrawfis
 * Date: 15 March 2016
 * Class: CSE 20212 Final Project
 * File: Message.cpp
 ************************************/

#include "Message.h"
#include "/usr/include/jsoncpp/json/json.h"

Message::Message()
{
    
}

Message::Message(string mesg)
{
    
}

/**************************************************
 * Function: packageMessageIntoJSON()
 * Purpose: Take what is messageContent, package
 *  it into a JSON object and save it as JSONstr;
 * Inputs: None
 * Outputs: None
 **************************************************/

void Message::packageMessageIntoJSON()
{
    
}

/**************************************************
 * Function: setMessage()
 * Purpose: setter for messageContent
 * Inputs:  string val, message to set
 * Outputs: None
 **************************************************/

void Message::setMessage(string val)
{
    messageContent = val;
}

/**************************************************
 * Function: getMessage()
 * Purpose: Getter for messageContent
 * Inputs: None
 * Outputs: None
 **************************************************/

string Message::getMessage()
{
    return messageContent;
}


