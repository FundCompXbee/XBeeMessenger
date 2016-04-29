// Team: XBeeMessenger
// Course: Fundamentals of Computing II
// Assignment: Final Project
// Purpose: Implementation of the Envelope class

#include "envelope.hpp"

#ifdef LOG1
#include "../loggerTesting/log1.h"
#else
#include "../loggerTesting/log.h"
#endif

// Private inheritance is utilised to provide a custom
// Envelope-specific interface, with the implementation benefits of
// jsoncpp's robust library for string inflation and deflation,
// construction, deconstruction, and [] operations

Envelope::Envelope() {
  FILELog::ReportingLevel() = FILELog::FromString(/*argv[1] ? argv[1] : */"DEBUG1"); // initializing logger
}

Envelope::Envelope(std::string str) {
  FILELog::ReportingLevel() = FILELog::FromString(/*argv[1] ? argv[1] : */"DEBUG1"); // initializing logger

  FILE_LOG(logDEBUG) << "Attempting to convert '" << str << "' to an envelope.";
  std::stringstream s(str);
  Json::operator>>(s,*this);
  FILE_LOG(logDEBUG) << "Envelope Conversion Complete.";
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

// Relies on jsoncpp
Envelope::Envelope(const Envelope& src) :
  Json::Value(src)
{
}

// Efficient move constructors are necessary due to the frequency of
// manipulation done to these objects, so the copy & swap idiom is
// implemented here and for operator=
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

// [] operator overload, which lets you access an key's corresponding value
Json::Value& Envelope::operator[](const char* str) {
  return Json::Value::operator[](str);
}

// overloading Json:Value:swap fuction
void Envelope::swap(Envelope& src) {
  // catch corrupted data
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
