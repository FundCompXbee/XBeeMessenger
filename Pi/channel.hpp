// Team: XBeeMessenger
// Course: Fundamentals of Computing II
// Assignment: Final Project
// Purpose: Interface for channels: shared spaces for users to
//          communicate in

#ifndef CHANNEL
#define CHANNEL

#include <map>
#include <string>
#include "user.hpp"

class Channel {
public:
  Channel(std::string channelName);
  std::string getName();

  void addUser(std::string userName);
  void removeUser(std::string userName);
  bool hasUser(std::string userName);
private:
  std::string name; // channel name

  // map that stores which users have joined the channel
  std::map<std::string, User> users;
};

#endif

