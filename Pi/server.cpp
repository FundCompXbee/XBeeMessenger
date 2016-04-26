#include "server.hpp"

const char Server::delimiter{'~'}; // sets delimiter, until which the serial is going to read in order to retrieve messages

// constructor, initializes serail to the specified baud rate and gets hostname
Server::Server(int baud) :
  serial("/dev/ttyAMA0", baud)
{
  char nameptr[255];
  if (gethostname(nameptr, 255) == 0) {
    name = nameptr;
  }
  else {
    std::cerr << "Error: Could not set name from hostname" << std::endl;
    exit(EXIT_FAILURE);
  }

  std::cout << "Server '" << name << "' Running..." << std::endl;
}


void Server::run() {
  std::string result;
  Envelope receivedEnv;
  Envelope broadcastEnv;
  while (true) {
    receivedEnv = Envelope(retrieveSerialData());
    //Verify envelope intended for this server
    std::cout << "Verifying request is for this server" << std::endl;
    if  (receivedEnv.getServer() != name && receivedEnv.getServer() != "") {
      std::cout << "NOT for this server CONFIRMED. SKIPPING" << std::endl;
      continue;
    }

    std::cout << "For this server CONFIRMED" << std::endl;
    std::cout << "Attempting to verfiy the request" << std::endl;
    result = verifyRequest(receivedEnv);
    std::cout << "Request Verification DONE" << std::endl;
    if (result == "server") {
      std::cout << "Envelope passed verification as server request..." << std::endl;
      std::cout << "Retrieved Envelope: '" << receivedEnv.toString() << "'" << std::endl;
      result = IRCHandler(receivedEnv.getExpression());
      std::cout << "IRCHandler Result: '" << result << "'" << std::endl;
      broadcastEnv = Envelope(name, receivedEnv.getSender(), "server", result);
    }
    else if (result == "channel") {
      std::cout << "Envelope passed verification as channel request ..." << std::endl;
      std::cout << "Retrieved Envelope: '" << receivedEnv.toString() << "'" << std::endl;
      result = IRCHandler(receivedEnv.getExpression());
      std::cout << "IRCHandler Result: '" << result << "'" << std::endl;
      broadcastEnv = Envelope(name, receivedEnv.getDestination(),
                              receivedEnv.getSender(), result);
    }
    else {
      std::cout << "Envelope failed verification..." << std::endl;
      broadcastEnv = Envelope(name, receivedEnv.getSender(), name, result);
      std::cout << "Failure notification sent..." << std::endl;
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
  std::cout << "Attempting broadcast..." << std::endl;
  serial.write(data+delimiter);
}

// retrives string from serial up until the delimiter
std::string Server::retrieveSerialData() {
  std::cout << "Attempting retrieval..." << std::endl;
  return serial.readUntil(delimiter);
}


