// Team: XBeeMessenger
// Course: Fundamentals of Computing II
// Assignment: Final Project
// Purpose: Implementation of the client class

#include "client.hpp"

#ifdef LOG1
#include "../loggerTesting/log1.h"
#else
#include "../loggerTesting/log.h"
#endif

const char Client::delimiter{'~'};

Client::Client(std::string userName, int baud) :
  serial("/dev/ttyACM0", baud),   // initializes serial-port
  userName(userName)
{
  FILELog::ReportingLevel() = FILELog::FromString(/*argv[1] ? argv[1] : */"DEBUG1"); // initializing logger
  FILE_LOG(logDEBUG) << "Finished constructing client '" << userName << "'.";
}

void Client::setUsername(std::string name) {
  FILE_LOG(logDEBUG) << "Sending request to set username to '" << name << "'.";
  sendExpression("server", "CHANGENAME "+name+" "+userName);
  userName = name;
}

// retrieves the servers on the network by making a ping request and
// retrieving the server responses
std::string Client::getServers() {
  std::string servers;
  FILE_LOG(logDEBUG) << "Attempting to get servers";
  FILE_LOG(logDEBUG) << "Sending Ping";
  sendExpression("server","PING");


  FILE_LOG(logDEBUG) << "About to get ping response." ;
  Envelope pong(retrieveEnvelope());
  FILE_LOG(logDEBUG) << "received server pong envelope '" << pong.toString() << "'";

  FILE_LOG(logDEBUG) << "About to try pong.getServer()";
    servers += pong.getServer()+"\n";
  FILE_LOG(logDEBUG) << "Everything went fine in getServers().";

  return servers;
}

void Client::connectServer(std::string server) {
  FILE_LOG(logDEBUG) << "Sending a request to '" << server << "' for connection.";
  sendExpression("server","CONNECT "+userName);
  serverName = server;
}

void Client::disconnectServer() {
  FILE_LOG(logDEBUG) << "Sending a request to '" << serverName << "' for disconnection.";
  sendExpression("server", "DISCONNECT "+serverName+" "+userName);
  serverName = "";
}

void Client::joinChannel(std::string channel) {
  FILE_LOG(logDEBUG) << "Sending a request to join '" << channel << "'.";
  sendExpression("server", "JOINCHANNEL "+channel+" "+userName);
  channels.insert(channel);
}

void Client::createChannel(std::string channel) {
  FILE_LOG(logDEBUG) << "Sending a request to join '" << channel << "'.";
  sendExpression("server", "CREATECHANNEL "+channel+" "+userName);
  channels.insert(channel);
}

// builds up an Envelope using the parameters and calls sendEnvelope()
void Client::sendExpression(std::string destination, std::string expression) {
  FILE_LOG(logDEBUG) << "Sending envelope to '" << destination << "'." ;
  sendEnvelope(Envelope(serverName, destination, userName, expression));
}

// writes envelope in  string fromat alongside delimiter to serial
void Client::sendEnvelope(Envelope env) {
  FILE_LOG(logDEBUG) << "Attemting to send envelope '" << env.toString() << "'.";
  serial.write(env.toString()+delimiter);
}

// Waits for a revelant broadcast and returns the corresponding Envelope
Envelope Client::retrieveEnvelope() {
  Envelope response;
  std::string data;

  // Filter broadcasts for those matching channels which are joined
  // the client's username
  while (response.getDestination() != userName &&
         channels.count(response.getDestination()) == 0) {
    FILE_LOG(logDEBUG) << "About to retrieve data for retrieveEnvelope.";
    data = serial.readUntil(delimiter);
    FILE_LOG(logDEBUG) << "Successfully got data for retrieveEnvelope().";

    FILE_LOG(logDEBUG) << "About to convert data to envelope for retrieveEnvelope().";
    response = Envelope(data);
    FILE_LOG(logDEBUG) << "Conversion complete.";
  }

  FILE_LOG(logDEBUG) << "Response envelope received...";
  return response;
}
