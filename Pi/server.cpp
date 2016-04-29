// Team: XBeeMessenger
// Course: Fundamentals of Computing II
// Assignment: Final Project
// Purpose: Implementation of the server interface

#include "server.hpp"

#ifdef LOG1
#include "../loggerTesting/log1.h"
#else
#include "../loggerTesting/log.h"
#endif

const char Server::delimiter{'~'};

// Initializes serial communications and gets hostname
Server::Server(int baud) :
  serial("/dev/ttyAMA0", baud)
{
  FILELog::ReportingLevel() = FILELog::FromString(/*argv[1] ? argv[1] : */"DEBUG1");
  FILE_LOG(logDEBUG) << "Initializing logger";

  char nameptr[255];
  if (gethostname(nameptr, 255) == 0) {
    name = nameptr;
  }
  else {
    FILE_LOG(logERROR) << "Error: Could not set server name from hostname";
    exit(EXIT_FAILURE);
  }

  FILE_LOG(logDEBUG) << "Server' " << name << "' Running... ";
}


void Server::run() {
  std::string result;
  Envelope receivedEnv;
  Envelope broadcastEnv;

  while (true) {
    // Receive any incoming request
    receivedEnv = Envelope(retrieveSerialData());
    FILE_LOG(logDEBUG) << "Retrieved Envelope: '" << receivedEnv.toString() << "'";

    // Verify request is intended for this server
    FILE_LOG(logDEBUG) << "Verifying Request is from Server.";
    if  (receivedEnv.getServer() != name && receivedEnv.getServer() != "") {
      FILE_LOG(logDEBUG) << "NOT for this server CONFIRMED, SKIPPING";
      continue;
    }

    // Make sure the request is sensible and allowed
    FILE_LOG(logDEBUG) << "For this server CONFIRMED";
    FILE_LOG(logDEBUG) << "Attempting to verfiy the request";
    result = validateRequest(receivedEnv);

    // Request is for the server
    if (result == "server") {
      FILE_LOG(logDEBUG) << "Envelope passed verification as server request...";
      result = IRCHandler(receivedEnv.getExpression());
      FILE_LOG(logDEBUG) << "IRCHandler Result: '" << result << "'" ;
      // Setup broadcast with result, from "server" to requester
      broadcastEnv = Envelope(name, receivedEnv.getSender(), "server", result);
    }
    // Request is targeted at a channel
    else if (result == "channel") {
      FILE_LOG(logDEBUG) << "Envelope passed verification as channel request ...";
      result = IRCHandler(receivedEnv.getExpression());
      FILE_LOG(logDEBUG) << "IRCHandler Result: '" << result << "'";
      broadcastEnv = Envelope(name, receivedEnv.getDestination(),
                              receivedEnv.getSender(), result);
    }
    else {
      FILE_LOG(logDEBUG) << "Envelope failed verification...";
      broadcastEnv = Envelope(name, receivedEnv.getSender(), "server", result);
      FILE_LOG(logDEBUG) << "Failure notification sent...";
    }

    // Broadcast the result of the request
    broadcastSerialData(broadcastEnv.toString());
  }
}

// Returns the target, if applicable, of a request ("server", "channel", else "")
//
// This abstracts a call to the IRCHandler incase server-only checks
// also need to be made
std::string Server::validateRequest(Envelope& env) {
  return IRCHandler.validateRequest(env.getDestination(),
                                    env.getSender(),
                                    env.getExpression());
}

// Broadcasts message by writing data to the serial buffer
void Server::broadcastSerialData(std::string data) {
  FILE_LOG(logDEBUG) << "Attempting broadcast...";
  serial.write(data+delimiter);
}

// retreives string from serial up until the delimiter
std::string Server::retrieveSerialData() {
  FILE_LOG(logDEBUG) << "Attempting retrieval...";
  return serial.readUntil(delimiter);
}


