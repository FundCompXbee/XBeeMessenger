#ifndef USER
#define USER

#include <string>

class User {
public:
  User();
  User(std::string);
  std::string getName();
  void setName(std::string);
private:
  std::string name;
};

#endif
