#ifndef ENVELOPE
#define ENVELOPE

#include <sstream>
#include <string>
#include "/usr/include/jsoncpp/json/json.h"

#include <iostream>

class Envelope : private Json::Value {
public:
  Envelope(); // default contructor
  Envelope(std::string); 	// constructor, build Json from string
  Envelope(std::string server,	// constructor, build Json from parameters
           std::string destination, 
           std::string sender,
           std::string expression);
  Envelope(const Envelope&);	// copy constructor
  Envelope(Envelope&& temp);	// copy constructor *
  Envelope& operator=(Envelope);// Equals operator overload
  std::string toString();	// returns Json in string format

  std::string getServer();	// returns value from Server key
  std::string getDestination();	// returns value from Destination key
  std::string getSender();	// returns value from Sender key
  std::string getExpression();	// returns value from Expression key

  void setServer(std::string);	// changes value from Server key 
  void setDestination(std::string); // changes value from Destination key
  void setSender(std::string);	// changes value from Sender key
  void setExpression(std::string);  // changes value from Expression key

private:
  Json::Value& operator[](const char* str); // [] operator overload,
  void swap(Envelope&); // overloading Json:Value:swap fuction

};

#endif
