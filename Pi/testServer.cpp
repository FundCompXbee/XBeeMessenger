#include "serial.hpp"
#include <boost/asio.hpp>
#include <iostream>
#include <string>

int main() {
  std::cout << "Initializing Server" << std::endl;
  Serial serial("/dev/ttyAMA0", 38400);
  std::cout << "Server Running..." << std::endl;
  std::string str;
  while (true) {
    str = serial.readUntil('~');
    std::cout << "New Message: " << str << std::endl;
  }
}
