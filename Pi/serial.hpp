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
  Serial(std::string port, unsigned int baud); // contructor, initializes serial port using boost
  ~Serial(); // deconstructor
  char getChar(); // returns single character from serial buffer
  std::string readUntil(char); 	// returns string read from buffer up until delimiter
  void write(std::string);	// writes string to serial buffer

private:
  boost::asio::streambuf buffer; 
  boost::asio::io_service io;
  boost::asio::serial_port serial;
};

#endif
