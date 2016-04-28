#include "envelope.hpp"

/*
 Envelope Class inherits from the Json:Value class and overloads
   some of it operators and functions in order create an Envelope
   object that resembles a Json object's functionality.
*/


Envelope::Envelope() { // default contructor
}

// contructor that builds Envelope from string
Envelope::Envelope(std::string str) {
  std::cout << "Attempting to convert '" << str << "' to an envelope" << std::endl;
  std::stringstream s(str);
  Json::operator>>(s,*this);
  std::cout << "Envelope Conversion Complete" << std::endl;
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
  swap(temp);
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
    std::cout << "trying to swap envelope '"+src.toString()+"'" << std::endl;
    std::cout << "src.getDestination() = '"+src.getDestination()+"'"<<std::endl;
    Json::Value::swap(src);
  }
  catch (...) {
    std::cout << "failed swap envelope, throwing" << std::endl;
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
