# // sets delimiter, until which the serial is going to read in order to retrieve messages
#include "client.hpp"
#ifdef LOG1
#include "../loggerTesting/log1.h"
#else
#include "../loggerTesting/log.h"
#endif

const char Client::delimiter{'~'}; // sets delimiter, until which the serial is going to read in order to retrieve messages

Client::Client(std::string userName, int baud) : // constructor
  serial("/dev/ttyACM0", baud),   // initializes serial-port
  userName(userName)      // sets client's userName
{
  FILELog::ReportingLevel() = FILELog::FromString(/*argv[1] ? argv[1] : */"DEBUG1"); // initializing logger
  FILE_LOG(logDEBUG) << "Finished constructing client '" << userName << "'.";
}

void Client::setUsername(std::string name) {  // sets client's userName
  FILE_LOG(logDEBUG) << "Sending request to set username to '" << name << "'.";
  sendExpression("server", "CHANGENAME "+name+" "+userName);
  userName = name;
}

// retrieves the servers on the network by making a ping request and retrieving the server response
std::string Client::getServers() {
  std::string servers;
  FILE_LOG(logDEBUG) << "Attempting to get servers";
  FILE_LOG(logDEBUG) << "Sending Ping";
  sendExpression("server","PING");
  Envelope pong;
  try {
    FILE_LOG(logDEBUG) << "About to get ping response." ;
    pong = retrieveEnvelope();
  }
  catch (...) {
    FILE_LOG(logDEBUG) <<  "Failed to get ping response, threw exception." ;
    throw;
  }
  FILE_LOG(logDEBUG) << "received server pong envelope '" << pong.toString() << "'";	
  try {
	FILE_LOG(logDEBUG) << "About to try pong.getServer()";
    servers += pong.getServer()+"\n";
  }
  catch (...) {
	FILE_LOG(logDEBUG) << "Faild to pong.getServer() throwing exception.";
    throw;
  }
  FILE_LOG(logDEBUG) << "Everything went fin in getServers().";
  return servers;
}

// connects to the server by sending an expressing and changes the serverName associated with the client
void Client::connectServer(std::string server) {
  FILE_LOG(logDEBUG) << "Sending a request to '" << server << "' for connection." ;
  sendExpression("server","CONNECT "+userName);
  serverName = server;
}

void Client::disconnectServer() {
  FILE_LOG(logDEBUG) << "Sending a request to '" << serverName << "' for disconnection." ;
  sendExpression("server", "DISCONNECT "+serverName+" "+userName);
  serverName = "";
}

// std::set<std::string> Client::getChannels() {
//   std::cout << "Attempting to get channel listing" << std::endl;
//   std::cout << "Sending a server request for getchannels" << std::endl;
//   sendServerRequest("GETCHANNELS");
//   std::cout << "server request for channel listing sent" << std::endl;

//   std::set<std::string> channels;
//   std::cout << "getting channel listing response..." << std::endl;
//   std::string response(retrieveResponse());
//   std::cout << "received channel listing response '" << response << "'" << std::endl;

//   std::cout << "splitting channel listing by spaces" << std::endl;
//   boost::split(channels, response, boost::is_any_of(" "));
//   std::cout << "split done" << std::endl;

//   std::cout << "returning channel set" << std::endl;
//   return channels;
// }

// adds a channel to the set of channels
void Client::joinChannel(std::string channel) {
  FILE_LOG(logDEBUG) << "Sending a request to join '" << channel << "'." ;
  sendExpression("server", "JOINCHANNEL "+channel+" "+userName);
  channels.insert(channel);
}

void Client::createChannel(std::string channel) {
  FILE_LOG(logDEBUG) << "Sending a request to join '" << channel << "'." ;
  sendExpression("server", "CREATECHANNEL "+channel+" "+userName);
  channels.insert(channel);
}

// builds up an Envelope using the parameters and calls sendEnvelope()
void Client::sendExpression(std::string destination, std::string expression) {
  // if (destination == "server") {
  //   std::cout << "sending a server request" << std::endl;
  //   sendServerRequest(expression);
  // }
  // else {
  //   std::cout << "sending a channel request" << std::endl;
  //   sendChannelRequest(expression);
  // }
  FILE_LOG(logDEBUG) << "Sending envelope to '" << destination << "'." ;
  sendEnvelope(Envelope(serverName, destination, userName, expression));
}


std::string Client::retrieveResponse() {
  FILE_LOG(logDEBUG) << "Attempting to retrieve a response envelope.";
  Envelope response(retrieveEnvelope());
  FILE_LOG(logDEBUG) << "Response envelope received...";
  return response.getExpression();
}

// calls retrieveEnvelope() to retrieve Enveloped from the serial until the Envelope's destiantion matches that of the client, then returns that Envelope's expression
std::string Client::retrieveResponse(std::string destinationToListenFor) {
  FILE_LOG(logDEBUG) << "Attempting to retrieve a response envelope.";
  Envelope response(retrieveEnvelope());s
  while (response.getDestination() != destinationToListenFor) {
    FILE_LOG(logDEBUG) << "Response envelope received...";
    response = retrieveEnvelope();
  }
  return response.getExpression();
}


// void Client::sendChannelRequest(std::string command) {
//   sendEnvelope(Envelope(serverName, channelName, userName, command));
// }

// void Client::sendServerRequest(std::string command) {
//   std::cout << "Sending server request for command '" << command << "'" << std::endl;
//   sendEnvelope(Envelope(serverName, "server", userName, command));
// }



// writes envelope in  string fromat alongside delimiter to serial
void Client::sendEnvelope(Envelope env) {
  FILE_LOG(logDEBUG) << "Attemting to send envelope '" << env.toString() << "'.";
  serial.write(env.toString()+delimiter);
}

// reads from serial until the delimiter, and returns an Envelope built from the retrieved string
Envelope Client::retrieveEnvelope() {
  Envelope response;
  std::string data;

  while (response.getDestination() != userName &&
         channels.count(response.getDestination()) == 0) {
	FILE_LOG(logDEBUG) << "Attemting to retrie envelope.";;
    FILE_LOG(logDEBUG) << "Attempting to convert to envelope.";
    try {
	  FILE_LOG(logDEBUG) << "About to retrieve data for retrieveEnvelope.";
      std::cout << "about to retrieve data for retrieveEnvelope" << std::endl;
      data = serial.readUntil(delimiter);
    }
    catch (...) {
	  FILE_LOG(logDEBUG) << "Failed to get data for retrieveEnvelope, throwing.";
      throw;
    }
	FILE_LOG(logDEBUG) << "Successfully got data for retrieveEnvelope().";

    try {
	  FILE_LOG(logDEBUG) << "About to convert data to envelope for retrieveEnvelope().";
      response = Envelope(data);
	  FILE_LOG(logDEBUG) << "Response envelope.tostring = '"+response.toString()+"'.";
    }
    catch (...) {
	  FILE_LOG(logDEBUG) << "Failed to convert data to envelope for retrieveEnvelope(), throwing.";
      throw;
    }
	FILE_LOG(logDEBUG) << "Conversion complete.";
	FILE_LOG(logDEBUG) << "Response envelope received...";
  }
  return response;
}
