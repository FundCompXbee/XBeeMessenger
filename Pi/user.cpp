#include "user.hpp"
#ifdef LOG1
#include "../loggerTesting/log1.h"
#else
#include "../loggerTesting/log.h"
#endif

/* Simple User class which stores the name of a particular user. 
*/

// constructor
User::User() {
}

// constructor, sets the name of the user to what is passed in as a parameter
User::User(std::string name) :
  name(name)
{
  FILELog::ReportingLevel() = FILELog::FromString(/*argv[1] ? argv[1] : */"DEBUG1");
  FILE_LOG(logDEBUG) << "Initializing user logger.";
  FILE_LOG(logDEBUG) << "Setting user name to '" << name << "'.";

}

// returns private data member name
std::string User::getName() {
  return name;
}

// serts name to that passed in as a parameter 
void User::setName(std::string n) {
  name = n;
}
