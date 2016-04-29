#include "envelope.hpp"
#ifdef LOG1
#include "../loggerTesting/log1.h"
#else
#include "../loggerTesting/log.h"
#endif

/*
 Envelope Class inherits from the Json:Value class and overloads
   some of it operators and functions in order create an Envelope
   object that resembles a Json object's functionality.
*/


Envelope::Envelope() { // default contructor
  FILELog::ReportingLevel() = FILELog::FromString(/*argv[1] ? argv[1] : */"DEBUG1"); // initializing logger
}

// contructor that builds Envelope from string
Envelope::Envelope(std::string str) {
  FILELog::ReportingLevel() = FILELog::FromString(/*argv[1] ? argv[1] : */"DEBUG1"); // initializing logger
  FILE_LOG(logDEBUG) << "Attempting to convert '" << str << "' to an envelope." ;
  std::stringstream s(str);
  Json::operator>>(s,*this);
  FILE_LOG(logDEBUG) << "Envelope Conversion Complete."; 
}

// constructor that builds Envelope from paramaeters
Envelope::Envelope(std::string server,
                   std::string destination,
                   std::string sender,
                   std::string expression) {
  setServer(server);
  setDestination(destination);
  setSender(sender);
  setExpression(expression);
}

// copy constructor
Envelope::Envelope(const Envelope& src) :
  Json::Value(src)
{
}

// copy constructor
Envelope::Envelope(Envelope&& temp) :
  Envelope()
{
  swap(temp);
}

// Equals operator overload
Envelope& Envelope::operator=(Envelope temp) {
  try {
    std::cout << "Envelope: '"+toString()+" isobject = "+(isObject()?"true":"false") << std::endl;
    swap(temp);
  }
  catch (...) {
    std::cout << "threw exception at '='" << std::endl;
    throw;
  }

  return *this;
}

// returns Json in string format
std::string Envelope::toString() {
  return this->toStyledString();
}

// [] operator overload, which lets you access an key's corresponding value
Json::Value& Envelope::operator[](const char* str) {
  return Json::Value::operator[](str);
}

// overloading Json:Value:swap fuction
void Envelope::swap(Envelope& src) {
  try {
	FILE_LOG(logDEBUG) << "Trying to swap envelope '"+src.toString()+"'.";
    if (!src.isObject()) {
	  FILE_LOG(logDEBUG) << "Env is not object, returning";
      return;
    }
    Json::Value::swap(src);
  }
  catch (...) {
	FILE_LOG(logDEBUG) << "Failed swap envelope, throwing" << std::endl;
    throw;
  }
}

// returns value from Server key
std::string Envelope::getServer() {
  return (*this)["Server"].asString();
}

// returns value from Destination key
std::string Envelope::getDestination() {
  return (*this)["Destination"].asString();
}

// returns value from Sender key
std::string Envelope::getSender() {
  return (*this)["Sender"].asString();
}

// returns value from Expression key
std::string Envelope::getExpression() {
  return (*this)["Expression"].asString();
}

// changes value from Server key
void Envelope::setServer(std::string str) {
  (*this)["Server"] = str;
}

// changes value from Destination key
void Envelope::setDestination(std::string str) {
  (*this)["Destination"] = str;
}

// changes value from Sender key
void Envelope::setSender(std::string str) {
  (*this)["Sender"] = str;
}

// changes value from Expression key
void Envelope::setExpression(std::string str) {
  (*this)["Expression"] = str;
}
