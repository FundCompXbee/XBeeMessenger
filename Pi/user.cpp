// Team: XBeeMessenger
// Course: Fundamentals of Computing II
// Assignment: Final Project
// Purpose: Interface for the representation of a user

#include "user.hpp"

User::User() {
}

User::User(std::string name) :
  name(name)
{
}

std::string User::getName() {
  return name;
}

void User::setName(std::string n) {
  name = n;
}
