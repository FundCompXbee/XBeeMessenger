#ifndef CHANNEL
#define CHANNEL

#include <map>
#include <string>
#include "user.hpp"

class Channel {
public:
  Channel(std::string); // constructor, which initializes the name of the channel
  std::string getName(); // returns name of the channel
  // maybe const ref?
  void addUser(std::string); // adds name : User key value pair to map of users in the channel
  void removeUser(std::string); // removes a User from the map
  bool hasUser(std::string);  // returns true if user key is in users map
private:
  std::string name; // channel name
  std::map<std::string, User> users; // map that stores which users are at a given channel

};

#endif

