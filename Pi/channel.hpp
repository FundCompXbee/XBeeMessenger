#ifndef CHANNEL
#define CHANNEL

#include <map>
#include <string>
#include "user.hpp"

class Channel {
public:
  Channel(std::string);
  std::string getName();
  // maybe const ref?
  void addUser(std::string);
  void removeUser(std::string);
  bool hasUser(std::string);
private:
  std::string name;
  std::map<std::string, User> users;

};

#endif

