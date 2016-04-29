#include "server.hpp"
#ifdef LOG1
#include "../loggerTesting/log1.h"
#else
#include "../loggerTesting/log.h"
#endif


const char Server::delimiter{'~'}; // sets delimiter, until which the serial is going to read in order to retrieve messages

// constructor, initializes serail to the specified baud rate and gets hostname
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
    FILE_LOG(logERROR) << "Error: Could not set name from hostname";
    exit(EXIT_FAILURE);
  }

  FILE_LOG(logDEBUG) << "Server' " << name << "' Runing... ";
}


void Server::run() {
  std::string result;
  Envelope receivedEnv;
  Envelope broadcastEnv;
  while (true) {
    receivedEnv = Envelope(retrieveSerialData());
    //Verify envelope intended for this server
    FILE_LOG(logDEBUG) << "Verifying Request is from Server.";
    if  (receivedEnv.getServer() != name && receivedEnv.getServer() != "") {
      FILE_LOG(logDEBUG) << "NOT for this server CONFIRMED, SKIPPING";
      continue;
    }
	FILE_LOG(logDEBUG) << "For this server CONFIRMED";
	FILE_LOG(logDEBUG) << "Attempting to verfiy the request";
    result = verifyRequest(receivedEnv);
	FILE_LOG(logDEBUG) << "Request Verification DONE";
    if (result == "server") {
	  FILE_LOG(logDEBUG) << "Envelope passed verification as server request...";
	  FILE_LOG(logDEBUG) << "Retrieved Envelope: '" << receivedEnv.toString() << "'" ;
      result = IRCHandler(receivedEnv.getExpression());
	  FILE_LOG(logDEBUG) << "IRCHandler Result: '" << result << "'" ;
      broadcastEnv = Envelope(name, receivedEnv.getSender(), "server", result);
    }
    else if (result == "channel") {
	  FILE_LOG(logDEBUG) << "Envelope passed verification as channel request ..." ;
      FILE_LOG(logDEBUG) << "Retrieved Envelope: '" << receivedEnv.toString() << "'";
      result = IRCHandler(receivedEnv.getExpression());	
	  FILE_LOG(logDEBUG) << "IRCHandler Result: '" << result << "'" << std::endl;
      broadcastEnv = Envelope(name, receivedEnv.getDestination(),
                              receivedEnv.getSender(), result);
    }
    else {
	  FILE_LOG(logDEBUG) <<	"Envelope failed verification..." ;
      broadcastEnv = Envelope(name, receivedEnv.getSender(), "server", result);
	  FILE_LOG(logDEBUG) <<	"Failure notification sent...";
    }

    broadcastSerialData(broadcastEnv.toString());
  }
}

//
std::string Server::verifyRequest(Envelope& env) {
  return IRCHandler.validateRequest(env.getDestination(),
                                    env.getSender(),
                                    env.getExpression());
}

// broadcasts message by writing data to the serial buffer
void Server::broadcastSerialData(std::string data) {
  FILE_LOG(logDEBUG) << "Attempting bradcast...";
  serial.write(data+delimiter);
}

// retrives string from serial up until the delimiter
std::string Server::retrieveSerialData() {
  FILE_LOG(logDEBUG) << "Attempting retrieval...";
  return serial.readUntil(delimiter);
}


