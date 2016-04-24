/***********************************
 * Student: Aaron Crawfis
 * netID: acrawfis
 * Date: 15 March 2016
 * Class: CSE 20212 Final Project
 * File: Packet.h
 ************************************/
#ifndef PACKET_H
#define PACKET_H

#include <string>
#include "/usr/include/jsoncpp/json/json.h"
#include <time.h>

using namespace std;

class Packet {
public:
    Packet();
//    Packet(str JSONstream);
    virtual void setJSONstr(string JSON);
    virtual void setSource(int src);
    virtual void setDestination(int dest);
    virtual void createTemplateJSON();
    virtual void printPacket();
    virtual void setSTRjson(Json::Value jObj);
    virtual string getJSONstr();
    //string getCleanJSONstr();
    virtual Json::Value getJSONobj();
    virtual void setField(string field, string value);
private:
    string JSONstr;
    string command;
    //string cleanJSONstr;
    Json::Value destinations;
    int source;
    time_t timestamp;
    Json::Value JSONobj;    
};

#endif
