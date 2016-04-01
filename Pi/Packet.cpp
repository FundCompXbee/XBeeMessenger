/*	    Aaron Crawfis
	    Jorge Diaz
 * netID: acrawfis
	  jdiazort
 * Date: 15 March 2016
 * Class: CSE 20212 Final Project
 * File: Packet.cpp
 ************************************/

#include "Packet.h"
#include <time.h>

Packet::Packet()
{
   createTemplateJSON();   
}
/*
Packet::Packet(str JSONstream)
{
    JSONstr = JSONstram;
    setJSONstr(JSONstr);    
    cout << JSONstream << " \n was stored as a JSON. " << endl;
}
*/

string Packet::getJSONstr()
{
    return JSONstr;
}

Json::Value Packet::getJSONobj() {
    return JSONobj;
}

void Packet::setField(string field, string value) {
    JSONobj[field]  = value;
    setSTRjson(JSONobj);
}

void Packet::createTemplateJSON() 
{
    // defining temporary values for test
    command = "+key";  // command is a placeholder for command values for communcation
    source = 1; 	// # assigned to sender
    Json::Value destinations; 
    struct tm * timeinfo;
    time(&timestamp);
    timeinfo = localtime(&timestamp);

    JSONobj["command"] = command;
    JSONobj["source"] = source;
    JSONobj["content"] = "";
    JSONobj["destinations"] = destinations;
    JSONobj["timestamp"] = asctime(timeinfo);

    setSTRjson(JSONobj);

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


