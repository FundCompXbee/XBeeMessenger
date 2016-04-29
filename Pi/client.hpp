// Team: XBeeMessenger
// Course: Fundamentals of Computing II
// Assignment: Final Project
// Purpose: Interface for clients who connect to servers, make
//          requests, and listen for responses

#ifndef CLIENT
#define CLIENT

#include <boost/algorithm/string.hpp>
#include "serial.hpp"
#include "envelope.hpp"
#include <string>
#include <set>

class Client {
public:
  Client(std::string userName, int baud);

  void setUsername(std::string newUsername);
  std::string getServers(); // Returns newline separated list of servers
  void connectServer(std::string serverName);
  void disconnectServer();

  // Start listening and contributing to a channel
  void joinChannel(std::string channelName);
   // Create a channel and join it
  void createChannel(std::string channelName);

  // Send an IRC Command expression as a request to a channel or
  // server
  void sendExpression(std::string destination, std::string expression);

  // Waits for a broadcast relevant to the client and returns it as an
  // envelope
  Envelope retrieveEnvelope();
private:
  static const char delimiter;  // Signals the end of a transmission

  Serial serial; // Handles data reception and broadcasting

  std::string userName;
  std::string serverName; // Server the client is currently connected to
  std::set<std::string> channels; // All channels the client has joined

  void sendEnvelope(Envelope); // Broadcasts an Envelope


};

#endif
