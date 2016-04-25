#ifndef SERIAL
#define SERIAL

#include <boost/asio.hpp>
#include <chrono>
#include <thread>
#include <istream>
#include <string>

#include <iostream>

class Serial {
public:
  Serial(std::string port, unsigned int baud);
  ~Serial();
  char getChar();
  std::string readUntil(char);
  void write(std::string);

private:
  boost::asio::streambuf buffer;
  boost::asio::io_service io;
  boost::asio::serial_port serial;
};

#endif
