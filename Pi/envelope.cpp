#include "envelope.hpp"

Envelope::Envelope() {
}

Envelope::Envelope(std::string str) {
  std::cout << "Attempting to convert '" << str << "' to an envelope" << std::endl;
  std::stringstream s(str);
  Json::operator>>(s,*this);
  std::cout << "Envelope Conversion Complete" << std::endl;
}

Envelope::Envelope(std::string server,
                   std::string destination,
                   std::string sender,
                   std::string expression) {
  setServer(server);
  setDestination(destination);
  setSender(sender);
  setExpression(expression);
}

Envelope::Envelope(const Envelope& src) :
  Json::Value(src)
{
}

Envelope::Envelope(Envelope&& temp) :
  Envelope()
{
  swap(temp);
}

Envelope& Envelope::operator=(Envelope temp) {
  swap(temp);
  return *this;
}

std::string Envelope::toString() {
  return this->toStyledString();
}

Json::Value& Envelope::operator[](const char* str) {
  return Json::Value::operator[](str);
}

void Envelope::swap(Envelope& src) {
  Json::Value::swap(src);
}

std::string Envelope::getServer() {
  return (*this)["Server"].asString();
}

std::string Envelope::getDestination() {
  return (*this)["Destination"].asString();
}

std::string Envelope::getSender() {
  return (*this)["Sender"].asString();
}

std::string Envelope::getExpression() {
  return (*this)["Expression"].asString();
}

void Envelope::setServer(std::string str) {
  (*this)["Server"] = str;
}

void Envelope::setDestination(std::string str) {
  (*this)["Destination"] = str;
}

void Envelope::setSender(std::string str) {
  (*this)["Sender"] = str;
}

void Envelope::setExpression(std::string str) {
  (*this)["Expression"] = str;
}
