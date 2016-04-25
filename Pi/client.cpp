#include "client.hpp"

const char Client::delimiter{'~'};

Client::Client(std::string userName, int baud) :
  serial("/dev/ttyACM0", baud),
  userName(userName)
{
  // std::cout << "finished constructing client '" << userName << std::endl;
}

void Client::setUsername(std::string name) {
  if (name != "" || name == "server") {
    return;
  }

  userName = name;
}

std::set<std::string> Client::getServers() {
  // std::cout << "Attempting to get servers" << std::endl;
  // std::cout << "Sending Ping" << std::endl;
  sendExpression("server","PING");
  // std::cout << "ping sent" << std::endl;

  std::set<std::string> servers;
  // std::cout << "getting server pong envelope..." << std::endl;
  Envelope pong(retrieveEnvelope());
  // std::cout << "received server pong envelope '" << pong.toString() << "'" << std::endl;
  servers.insert(pong.getServer());

    // std::cout << "returning server set" << std::endl;
  return servers;
}

void Client::connectToServer(std::string server) {
    // std::cout << "Sending a request to '" << server << "' for connection" << std::endl;
  sendExpression("server","CONNECT "+userName);
  serverName = server;
}

// std::set<std::string> Client::getChannels() {
//   std::cout << "Attempting to get channel listing" << std::endl;
//   std::cout << "Sending a server request for getchannels" << std::endl;
//   sendServerRequest("GETCHANNELS");
//   std::cout << "server request for channel listing sent" << std::endl;

//   std::set<std::string> channels;
//   std::cout << "getting channel listing response..." << std::endl;
//   std::string response(retrieveResponse());
//   std::cout << "received channel listing response '" << response << "'" << std::endl;

//   std::cout << "splitting channel listing by spaces" << std::endl;
//   boost::split(channels, response, boost::is_any_of(" "));
//   std::cout << "split done" << std::endl;

//   std::cout << "returning channel set" << std::endl;
//   return channels;
// }

void Client::joinChannel(std::string channel) {
    // std::cout << "Attempting to join a channel '" << channel << "'" << std::endl;
//   sendChannelRequest("JOINCHANNEL "+channel+' '+userName);
  channels.insert(channel);
}

void Client::sendExpression(std::string destination, std::string expression) {
  // if (destination == "server") {
  //   std::cout << "sending a server request" << std::endl;
  //   sendServerRequest(expression);
  // }
  // else {
  //   std::cout << "sending a channel request" << std::endl;
  //   sendChannelRequest(expression);
  // }
  sendEnvelope(Envelope(serverName, destination, userName, expression));
}

std::string Client::retrieveResponse() {
    // std::cout << "Attempting to retrieve a response envelope" << std::endl;
  Envelope response(retrieveEnvelope());
  while (response.getDestination() != userName &&
         channels.count(response.getDestination()) == 0) {
      // std::cout << "Response envelope received......" << std::endl;
    response = retrieveEnvelope();
  }
    // std::cout << "RELEVANT response envelope received" << std::endl;

    // std::cout << "converting envelope to string and returning" << std::endl;
  return response.getExpression();
}

// void Client::sendChannelRequest(std::string command) {
//   sendEnvelope(Envelope(serverName, channelName, userName, command));
// }

// void Client::sendServerRequest(std::string command) {
//   std::cout << "Sending server request for command '" << command << "'" << std::endl;
//   sendEnvelope(Envelope(serverName, "server", userName, command));
// }

void Client::sendEnvelope(Envelope env) {
    // std::cout << "Attempting to send envelope '" << env.toString() << "'" << std::endl;
  serial.write(env.toString()+delimiter);
}

Envelope Client::retrieveEnvelope() {
    // std::cout << "Attempting to retrieve an envelope" << std::endl;
  std::string resp(serial.readUntil(delimiter));
    // std::cout << "  retrieved string: '" << resp << "'" << std::endl;
    // std::cout << "  Attempting to convert to envelope" << std::endl;
  Envelope env(resp);
    // std::cout << "  Conversion complete" << std::endl;
  return env;
}
