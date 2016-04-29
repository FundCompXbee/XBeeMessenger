// Team: XBeeMessenger
// Course: Fundamentals of Computing II
// Assignment: Final Project
// Purpose: Implementation of the channel class

#include "channel.hpp"

#ifdef LOG1
#include "../loggerTesting/log1.h"
#else
#include "../loggerTesting/log.h"
#endif

Channel::Channel(std::string name) :
  name(name)
{
  FILELog::ReportingLevel() = FILELog::FromString(/*argv[1] ? argv[1] : */"DEBUG1"); // initializing logger
  FILE_LOG(logDEBUG) << "Creating channel.";
}

std::string Channel::getName() {
  return name;
}

void Channel::addUser(std::string name) {
  FILE_LOG(logDEBUG) << "Adding user.";
  users.emplace(name, User(name));
}

void Channel::removeUser(std::string name) {
  FILE_LOG(logDEBUG) << "Removing user.";
  users.erase(name);
}

bool Channel::hasUser(std::string user) {
  return users.count(user);
}
