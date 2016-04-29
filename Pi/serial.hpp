// Team: XBeeMessenger
// Course: Fundamentals of Computing II
// Assignment: Final Project
// Purpose: Interface for a serial object that can read and write on a
//          serial port

#ifndef SERIAL
#define SERIAL

#include <boost/asio.hpp>
#include <chrono>
#include <thread>
#include <istream>
#include <string>

class Serial {
public:
  Serial(std::string portPath, unsigned int baud);
  ~Serial();

  // collects serial data up to, but not including, a delimiter and
  // returns data as a string
  std::string readUntil(char delimiter);

  // serializes some string of input and sends it to the serial port
  void write(std::string input);

private:
  boost::asio::streambuf buffer; // holds data collected during reads
  boost::asio::io_service io; // handles input and output to serial ports
  boost::asio::serial_port serial; // represents a serial port
};

#endif
