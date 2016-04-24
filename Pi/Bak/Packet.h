/***********************************
 * Student: Aaron Crawfis
 * netID: acrawfis
 * Date: 15 March 2016
 * Class: CSE 20212 Final Project
 * File: Packet.h
 ************************************/

#include <string>
#include "/usr/include/jsoncpp/json/json.h"

using namespace std;

class Packet {
public:
    Packet();
    
    void setJSONstr(string JSON);
    void setSource(int src);
    void setDestination(int dest);
    void createTemplateJSON();
    void printPacket();
    void setSTRjson(Json::Value jObj);
    string getJSONstr();
    //string getCleanJSONstr();
private:
    string JSONstr;
    //string cleanJSONstr;
    int destination;
    int source;
    int timeStamp;
    Json::Value JSONobj;    
};
