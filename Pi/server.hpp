#ifndef SERVER
#define SERVER

#include <string>
#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include "IRCCommandHandler.hpp"
#include "serial.hpp"
#include "envelope.hpp"

class Server {
public:
  Server(int baud); // contructor, initializes serial and gets hostname
  void run();
private:
  static const char delimiter;

  std::string name;
  IRCCommandHandler IRCHandler;
  Serial serial;

  std::string retrieveSerialData(); // retrives string from serial
  void broadcastSerialData(std::string); // broadcasts message by writing to serial buffer
  std::string verifyRequest(Envelope&);
};

#endif
