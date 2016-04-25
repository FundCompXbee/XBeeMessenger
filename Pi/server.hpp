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
  Server(int baud);
  void run();
private:
  static const char delimiter;

  std::string name;
  IRCCommandHandler IRCHandler;
  Serial serial;

  std::string retrieveSerialData();
  void broadcastSerialData(std::string);
  std::string verifyRequest(Envelope&);
};

#endif
