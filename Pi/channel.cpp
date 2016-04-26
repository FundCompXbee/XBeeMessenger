#include "channel.hpp"

Channel::Channel(std::string name) :  // constructor, which initializes the name of the channel
  name(name)
{
}

std::string Channel::getName() { // returns name of the channel
  return name;
}

void Channel::addUser(std::string name) {  // adds name : User key value pair to map of users in the channel 
  // check for collisions
  users.emplace(name, User(name));
}

void Channel::removeUser(std::string name) {  // removes a User from the map
  users.erase(name);
}

bool Channel::hasUser(std::string user) { // returns true if user key is in users map
  return users.count(user);
}
