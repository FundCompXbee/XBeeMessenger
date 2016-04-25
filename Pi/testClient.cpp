#include "serial.hpp"
#include "envelope.hpp"
#include "client.hpp"
#include <string>
#include <iostream>

int main() {
  Serial serial("/dev/ttyACM0", 38400);
  char delim = '~';
  std::cout << "Ready to test" << std::endl;
  std::string str;
  std::string response;
  Envelope env;
  while (true) {
    std::cout << "Server: ";
    std::getline(std::cin, str);
    env.setServer(str);

    std::cout << "Destination: ";
    std::getline(std::cin, str);
    env.setDestination(str);

    std::cout << "Sender: ";
    std::getline(std::cin, str);
    env.setSender(str);

    std::cout << "Expression: ";
    std::getline(std::cin, str);
    env.setExpression(str);

    serial.write(env.toString()+delim);
    std::cout << "Sent Message: '" << env.toString() << "~'"
              << "Waiting for reply..." << std::endl;
    response = serial.readUntil(delim);
    std::cout << "Received reply: '" << response << "'" << std::endl;
  }
}
