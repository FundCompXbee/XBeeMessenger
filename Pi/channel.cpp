#include "channel.hpp"

Channel::Channel(std::string name) :
  name(name)
{
}

std::string Channel::getName() {
  return name;
}

void Channel::addUser(std::string name) {
  // check for collisions
  users.emplace(name, User(name));
}

void Channel::removeUser(std::string name) {
  users.erase(name);
}

bool Channel::hasUser(std::string user) {
  return users.count(user);
}
