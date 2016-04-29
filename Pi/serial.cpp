// Team: XBeeMessenger
// Course: Fundamentals of Computing II
// Assignment: Final Project
// Purpose: Implementation of the serial interface

#include "serial.hpp"

#ifdef LOG1
#include "../loggerTesting/log1.h"
#else
#include "../loggerTesting/log.h"
#endif

Serial::Serial(std::string portPath, unsigned int baud) :
  io(),
  serial(io, portPath) // construct serial port from file path to the port
{
  FILELog::ReportingLevel() = FILELog::FromString(/*argv[1] ? argv[1] : */"DEBUG1"); // initializing logger
  FILE_LOG(logDEBUG) << "Initializing Serial logger." ;

  // Set options required to read XBee input as serial data
  serial.set_option(boost::asio::serial_port_base::baud_rate(baud));
  serial.set_option(boost::asio::serial_port_base::character_size(8));
  serial.set_option(boost::asio::serial_port_base::flow_control(boost::asio::serial_port_base::flow_control::none));
  serial.set_option(boost::asio::serial_port_base::parity(boost::asio::serial_port_base::parity::none));
  serial.set_option(boost::asio::serial_port_base::stop_bits(boost::asio::serial_port_base::stop_bits::one));

  // Wait for the port to finish setting up
  std::this_thread::sleep_for(std::chrono::seconds(2));
}

Serial::~Serial() {
  serial.close();
}

std::string Serial::readUntil(char delim) {
  FILE_LOG(logDEBUG) << "Attempting read_until...";
  boost::asio::read_until(serial, buffer, delim);
  FILE_LOG(logDEBUG) << "Done read_until.";

  FILE_LOG(logDEBUG) << "Attempting string conversion...";
  std::istream is(&buffer);
  std::string target;
  std::getline(is, target, delim);
  FILE_LOG(logDEBUG) << "Done with string conversion, returning.";

  return target;
}

void Serial::write(std::string s) {
  boost::asio::write(serial,boost::asio::buffer(s.c_str(),s.size()));
}

