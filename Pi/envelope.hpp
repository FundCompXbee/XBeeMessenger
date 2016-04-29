// Team: XBeeMessenger
// Course: Fundamentals of Computing II
// Assignment: Final Project
// Purpose: Interface for Evelope objects to be sent between servers
//          and clients

#ifndef ENVELOPE
#define ENVELOPE

#include <sstream>
#include <string>
#include <json/json.h>

class Envelope : private Json::Value {
public:
  Envelope();
  Envelope(std::string jsonString); // inflates Json Object from string
  Envelope(std::string server,
           std::string destination,
           std::string sender,
           std::string expression);
  Envelope(const Envelope&);
  Envelope(Envelope&&);
  Envelope& operator=(Envelope);
  std::string toString(); // returns deflated Json as a string

  // Getters
  std::string getServer();
  std::string getDestination();
  std::string getSender();
  std::string getExpression();

  // Setters
  void setServer(std::string server);
  void setDestination(std::string dest);
  void setSender(std::string sender);
  void setExpression(std::string expr);

private:
  Json::Value& operator[](const char* str);
  void swap(Envelope&);
};

#endif
