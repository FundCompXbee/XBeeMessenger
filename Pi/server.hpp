// Team: XBeeMessenger
// Course: Fundamentals of Computing II
// Assignment: Final Project
// Purpose: Interface for a server which receives requests, handles
//          requests, and broadcasts responses

#ifndef SERVER
#define SERVER

#include <string>
#include <unistd.h>
#include <cstdlib>
#include "IRCCommandHandler.hpp"
#include "serial.hpp"
#include "envelope.hpp"

class Server {
public:
  Server(int baud); // contructor, initializes serial and gets hostname
  void run(); // Sets the server into action
private:
  static const char delimiter; // signals the end of a serial transmission

  std::string name; // The server's name. By default this is retrieved from the
                    // server's hostname

  IRCCommandHandler IRCHandler; // Handles commands
  Serial serial; // Handles data transmission

  std::string retrieveSerialData(); // retrieves raw JSON-string from serial
  void broadcastSerialData(std::string broadcastMessage); // broadcasts message
  std::string validateRequest(Envelope& request);
};

#endif
