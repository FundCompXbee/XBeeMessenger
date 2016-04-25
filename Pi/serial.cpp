#include "serial.hpp"

Serial::Serial(std::string port, unsigned int baud) :
  io(),
  serial(io, port)
{
  serial.set_option(boost::asio::serial_port_base::baud_rate(baud));
  serial.set_option(boost::asio::serial_port_base::character_size(8));
  serial.set_option(boost::asio::serial_port_base::flow_control(boost::asio::serial_port_base::flow_control::none));
  serial.set_option(boost::asio::serial_port_base::parity(boost::asio::serial_port_base::parity::none));
  serial.set_option(boost::asio::serial_port_base::stop_bits(boost::asio::serial_port_base::stop_bits::one));
  std::this_thread::sleep_for(std::chrono::seconds(2));
}

Serial::~Serial() {
  serial.close();
}

char Serial::getChar() {
  char c;
  boost::asio::read(serial,boost::asio::buffer(&c,1));
  return c;
}

std::string Serial::readUntil(char delim) {
  std::cout << "Attempting read_until..." << std::endl;
  boost::asio::read_until(serial, buffer, delim);
  std::cout << "Done read_until\n"
            << "Attempting string conversion..." << std::endl;
  std::istream is(&buffer);
  std::string target;
  std::getline(is, target, delim);
  std::cout << "Done with string conversion, returning" << std::endl;
  return target;
}

void Serial::write(std::string s) {
  boost::asio::write(serial,boost::asio::buffer(s.c_str(),s.size()));
}

