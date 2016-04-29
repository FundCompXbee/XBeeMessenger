// Team: XBeeMessenger
// Course: Fundamentals of Computing II
// Assignment: Final Project
// Purpose: Main execution of a server

#include <iostream>
#include "server.hpp"

#define BAUD_RATE 38400

int main()
{
  // Create Server
  std::cout << "Opening Pi Server" << std::endl;
  Server s(BAUD_RATE);

  // Run Server
  std::cout << "Running Pi Server" << std::endl;
  s.run();
}
