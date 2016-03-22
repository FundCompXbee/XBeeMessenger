/***********************************
 * Student: Aaron Crawfis
 * netID: acrawfis
 * Date: 15 March 2016
 * Class: CSE 20212 Final Project
 * File: Packet.h
 ************************************/

#include <string>

using namespace std;

class Packet {
public:
    Packet();
    ~Packet();
    void setJSONstr(string JSON);
    void setSource(int src);
    void setDestination(int dest);
private:
    string JSONstr;
    int destination;
    int source;
    int timeStamp;
    
};