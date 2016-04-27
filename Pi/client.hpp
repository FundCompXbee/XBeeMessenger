#ifndef CLIENT
#define CLIENT

#include <boost/algorithm/string.hpp>
#include "serial.hpp"
#include "envelope.hpp"
#include <string>
#include <set>
#include <chrono>
#include <iostream>

class Client {
public:
  Client(std::string, int);  // constructor

  void setUsername(std::string); // sets client's userName
  std::string getServers(); // returns the set of servers on the network
  void connectServer(std::string); // connects to the server and changes te serverName
  void disconnectServer(); // disconnects from the server and changes te serverName

  // std::set<std::string> getChannels();
  void joinChannel(std::string); // adds a channel to the list of channels
  void createChannel(std::string); // adds a channel to the list of channels

  void sendExpression(std::string, std::string); // biulds Envelope and sends expression
  std::string retrieveResponse(std::string destinationToListenFor); // retrieves expression from Envelope in serial  when evelope has the clients userName as destination
  std::string retrieveResponse(); // retrieves expression from Envelope in serial  when evelope has the clients userName as destination
  Envelope retrieveEnvelope(); // reads from serial until the delimiter, and returns an Envelope built from the retrieved string
private:
  static const char delimiter;  // sets delimiter, until which the serial is going to read in order to retrieve messages

  Serial serial; // creates serial

  std::string userName;
  std::string serverName;
  std::set<std::string> channels;

  // void sendChannelRequest(std::string);
  // void sendServerRequest(std::string);
  void sendEnvelope(Envelope); // writes envelope in  string fromat alongside delimiter to serial


};

#endif
