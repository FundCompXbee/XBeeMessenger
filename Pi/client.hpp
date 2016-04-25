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
  Client(std::string, int);

  void setUsername(std::string);

  std::set<std::string> getServers();
  void connectToServer(std::string);

  // std::set<std::string> getChannels();
  void joinChannel(std::string);

  void sendExpression(std::string, std::string);
  std::string retrieveResponse();
private:
  static const char delimiter;
  Serial serial;

  std::string userName;
  std::string serverName;
  std::set<std::string> channels;

  // void sendChannelRequest(std::string);
  // void sendServerRequest(std::string);
  void sendEnvelope(Envelope);
  Envelope retrieveEnvelope();
};

#endif
