#ifndef ENVELOPE
#define ENVELOPE

#include <sstream>
#include <string>
#include "/usr/include/jsoncpp/json/json.h"

#include <iostream>

class Envelope : private Json::Value {
public:
  Envelope();
  Envelope(std::string);
  Envelope(std::string server,
           std::string destination,
           std::string sender,
           std::string expression);
  Envelope(const Envelope&);
  Envelope(Envelope&& temp);
  Envelope& operator=(Envelope);
  std::string toString();

  std::string getServer();
  std::string getDestination();
  std::string getSender();
  std::string getExpression();

  void setServer(std::string);
  void setDestination(std::string);
  void setSender(std::string);
  void setExpression(std::string);

private:
  Json::Value& operator[](const char* str);
  void swap(Envelope&);

};

#endif
