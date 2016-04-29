// Team: XBeeMessenger
// Course: Fundamentals of Computing II
// Assignment: Final Project
// Purpose: This is a light weight testing client.
//          FOR TESTING AND EXAMPLES ONLY

#include "client.hpp"
#include <string>
#include <iostream>
#include <set>

// this is a light weight testing client.
// FOR TESTING AND EXAMPLES ONLY

int main() {
  Client client("conrad", 38400);
  std::cout << "Ready to test" << std::endl;
  std::string str;

  std::string servers = client.getServers();
  std::cout << "Servers:" << std::endl;
  std::cout << servers;
  std::cout << "Connect to: ";
  std::getline(std::cin, str);
  client.connectServer(str);
  std::cout << "Response: " << client.retrieveEnvelope().getExpression() << std::endl;

  std::string dest;
  std::string expr;
  while (true) {
    std::cout << "\n\nDestination: ";
    std::getline(std::cin, dest);

    std::cout << "IRC Expression: ";
    std::getline(std::cin, expr);

    if (expr.substr(0, 11) == "JOINCHANNEL" ||
        expr.substr(0, 13) == "CREATECHANNEL") {
      // std::cout << "adding channel '"
      //           << expr.substr(expr.find(' ')+1, expr.rfind(' ')-expr.find(' ')-1)
      //           << "'" << std::endl;
      client.joinChannel(expr.substr(expr.find(' ')+1, expr.rfind(' ')-expr.find(' ')-1));
    }
    client.sendExpression(dest, expr);
    // std::cout << "Sent Expression\n"
    //           << "Waiting for reply..." << std::endl
    //           << "Received reply: '" << client.retrieveResponse() << "'" << std::endl;
    std::cout << "Response: " << client.retrieveEnvelope().getExpression() << std::endl;
  }

}
