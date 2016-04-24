/*	    Aaron Crawfis
	    Jorge Diaz
 * netID: acrawfis
	  jdiazort
 * Date: 15 March 2016
 * Class: CSE 20212 Final Project
 * File: Packet.cpp
 ************************************/

#include "Packet.h"

Packet::Packet()
{
    createTemplateJSON();   
    setSTRjson(JSONobj);
}

string Packet::getJSONstr(){
    return JSONstr;
}

void Packet::createTemplateJSON() {
    // defining temporary values for test
    string command = "+key";  // command is a placeholder for command values for communcation
    int source = 1; 	// # assigned to sender
    Json::Value destinations; 
    destinations.append(2);
    destinations.append(3); 
    string message = "Hello World, this is just a test run.";
    string timestamp = "03/23/2016 15:30:00.0.0";

    JSONobj[command] = command;
    JSONobj["source"] = source;
    JSONobj["destinations"] = destinations;
    JSONobj["message"] = message;
    JSONobj["timestamp"] = timestamp;

}

// Builds JSON from incoming string?
void Packet::setJSONstr(string inSTR)
{
    Json::Value parsedFromString;
    Json::Reader reader;
    bool parsingSuccessful = reader.parse(inSTR,parsedFromString);
    if (parsingSuccessful)
    	JSONobj = parsedFromString;
}

// Converts JSON to a String for delivery
void Packet::setSTRjson(Json::Value jObj)
{
    Json::FastWriter fastWriter;
    JSONstr = fastWriter.write(jObj);
}


void Packet::setDestination(int dest)
{
    destination = dest;
    JSONobj["destinations"].append(dest);
}

void Packet::setSource(int src)
{
    source = src;
    JSONobj["source"]=src;
}

void Packet::printPacket() {
    Json::StyledWriter styledWriter;
    cout << styledWriter.write(JSONobj);
}
