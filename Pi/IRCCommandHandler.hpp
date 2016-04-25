#ifndef IRCCOMMANDHANDLER
#define IRCCOMMANDHANDLER

#include <boost/algorithm/string.hpp>
#include <string>
#include <vector>
#include <map>
#include "channel.hpp"
#include "user.hpp"

#include <iostream>

class IRCCommandHandler {
public:
  IRCCommandHandler();
  std::string operator()(std::string expression);
  std::string validateRequest(std::string dest,
                              std::string sender,
                              std::string expression);
private:
  std::string expression;
  std::string command;
  std::vector<std::string> arguments;
  // Containers
  std::map<std::string, User> users; // channel users should be references here
  std::map<std::string, Channel> channels;
  // For parsing
  bool validExpression();
  void parse();
  // For functionality
  std::string message();
  std::string connect();
  std::string createChannel();
  std::string getChannels();
  std::string joinChannel();
  std::string ping();
};

#endif
