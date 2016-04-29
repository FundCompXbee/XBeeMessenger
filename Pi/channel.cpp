#include "channel.hpp"
#ifdef LOG1
#include "../loggerTesting/log1.h"
#else
#include "../loggerTesting/log.h"
#endif

Channel::Channel(std::string name) :  // constructor, which initializes the name of the channel
  name(name)
{
  FILELog::ReportingLevel() = FILELog::FromString(/*argv[1] ? argv[1] : */"DEBUG1"); // initializing logger
  FILE_LOG(logDEBUG) << "Creating channel.";
}

std::string Channel::getName() { // returns name of the channel
  return name;
}

void Channel::addUser(std::string name) {  // adds name : User key value pair to map of users in the channel 
  // check for collisions
  FILE_LOG(logDEBUG) << "Adding user.";
  users.emplace(name, User(name));
}

void Channel::removeUser(std::string name) {  // removes a User from the map
  FILE_LOG(logDEBUG) << "Removing user.";
  users.erase(name);
}

bool Channel::hasUser(std::string user) { // returns true if user key is in users map
  return users.count(user);
}
