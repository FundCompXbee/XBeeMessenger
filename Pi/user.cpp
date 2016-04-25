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
