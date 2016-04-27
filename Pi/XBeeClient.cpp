#include "client.hpp"
#include <string>
#include <iostream>
#include <set>

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
  std::cout << "Response: " << client.retrieveResponse() << std::endl;

  // std::set<std::string> channels = client.getChannels();
  // std::cout << "Channels:" << std::endl;
  // for (auto channel : channels) {
  //   std::cout << "\t" << channel << std::endl;
  // }
  // std::cout << "\tNone" << std::endl;
  // while (channels.count(str) == 0 && str != "None") {
  //   std::cout << "Join: ";
  //   std::getline(std::cin, str);
  // }
  // if (str != "None") {
  //   client.joinChannel(str);
  //   std::cout << client.retrieveResponse() << std::endl;
  // }

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
    std::cout << "Response: " << client.retrieveResponse() << std::endl;
  }

}
