// Team: XBeeMessenger
// Course: Fundamentals of Computing II
// Assignment: Final Project
// Purpose: Interface for a user who makes a connection to a server

#ifndef USER
#define USER

#include <string>

class User {
public:
  User();
  User(std::string userName);
  std::string getName();
  void setName(std::string newName);
private:
  std::string name;
};

#endif
