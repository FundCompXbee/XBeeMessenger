/**************************************
 * Student: Aaron Crawfis, Jorge Diaz
 * netID: acrawfis
 * Date: 15 March 2016
 * Class: CSE 20212 Final Project
 * File: Message.h
 ***************************************/

#include <string>
#include "/usr/include/jsoncpp/json/json.h"

class Message
{
public:
    // Constructors
    Message();
    Message(string mesg);
    
    /******* Member Functions ********/
    
    // Message getters/setters
    void setMessage(string val);
    string getMessage();
    // JSON management
    void packageMessageIntoJSON();
    void packageObjectIntoJSON(Json::Value jObj);
    string getJSONstr();
    // Destination/Source Management
    void setSource(int src);
    void setDestination(int dest);
    
private:
    // Data Members
    string messageContent;
    string JSONstr;
    Json::Value JSONobj;
    
    int destination;
    int source;
    int timeStamp;
    
    // Helper Function
    void setJSONstr(string JSON);
};