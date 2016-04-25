#include "IRCCommandHandler.hpp"

IRCCommandHandler::IRCCommandHandler() {
}

std::string IRCCommandHandler::operator()(std::string exp) {
  expression = exp;
  if (!validExpression()) {
    return "Invalid IRC Expresssion: "+expression;
  }

  parse();

  std::cout << "Command = " << command << std::endl;
  std::cout << "Attempting to run COMMAND..." << std::endl;
  std::string result;
  if (command == "MSG") result = message();
  else if (command == "CONNECT") result = connect();
  else if (command == "CREATECHANNEL") result = createChannel();
  else if (command == "GETCHANNELS") result = getChannels();
  else if (command == "JOINCHANNEL") result = joinChannel();
  else if (command == "PING") result = ping();
  else result = "Invalid IRC Command '" + command + "'";

  return result;
}

bool IRCCommandHandler::validExpression() {
  // Something should be here. Maybe. I think. IDK what though...
  return true;
}

std::string IRCCommandHandler::validateRequest(std::string dest,
                                               std::string sender,
                                               std::string exp) {
  //This was just supposed to be a sender/dest validation function. Something
  //that returned a bool for legal and illegal combinations of dest and sender.
  // If we could get "expression" out of this it would be preferable

  // Server Requests
  if (dest == "server") {
  std::cout << "Testing server requests" << std::endl;
    // Try Connect Request if user not found
    if (!users.count(sender)) {
      std::cout << "Testing connect request" << std::endl;
      std::string c(exp.substr(0,7));
      if (c != "CONNECT" && c != "PING") {
        std::cout << "Testing expressiong for CONNECT" << std::endl;
        return "Error: Sender '" + sender + "' not found OR Invalid 'CONNECT' request";
      }
      std::cout << "Valid CONNECT request confirmed!" << std::endl;
    }
    std::cout << "Valid Server Request confiremd!" << std::endl;
    return "server";
  }
  // A channel request
  else {
    std::cout << "Testing channel request" << std::endl;
    // An invalid channel request
    if (!channels.count(dest)) {
      return "Error: Invalid Destination '" + dest + "' does not exist";
    }
    // A valid channel request
    else {
      std::cout << "Valid Channel request confirmed" << std::endl;
      std::cout << "Testing Channel permissions" << std::endl;
      // Channel permissions error
      if (!channels.at(dest).hasUser(sender)) {
        return "Error: User '" + sender + "' does not belong to channel '" + dest + "'";
      }
      std::cout << "Valid channel permissions confirmed!" << std::endl;
    }
    std::cout << "Valid channel request confirmed!" << std::endl;
    return "channel";
  }

  // Valid request
  std::cout << "valid request confirmed" << std::endl;
  return "";
}

void IRCCommandHandler::parse() {
  std::cout << "Beginning parse...\n"
            << "Beginning split..." << std::endl;
  boost::split(arguments, expression, boost::is_any_of(" "));
  std::cout << "Splitting Done" << std::endl;
  command = arguments.front();
  std::cout << "Command Parsing Done" << std::endl;
  arguments.erase(arguments.begin());
  std::cout << "Arguments Parsing Done\n"
            << "Parsing Done" << std::endl;
}

std::string IRCCommandHandler::message() {
  // MSG message contents here
  return expression.substr(4);
}

std::string IRCCommandHandler::connect() {
  // CONNECT username
  std::string user{arguments[0]};

  std::string result;
  if (users.count(user) || user == "server") {
    result = "Error: User '"+user+"' already exists on the server";
  }
  else {
    users.emplace(user, User(user));
    result = "Successfully connected "+user;
  }
  return result;
}

std::string IRCCommandHandler::createChannel() {
  // CREATECHANNEL channelname username
  std::string channel{arguments[0]};
  std::string user{arguments[1]};

  std::string result;
  if (channels.count(channel) || channel == "server") {
    result = "Error: Channel '"+channel+"' already exists";
  }
  else {
    channels.emplace(channel, Channel(channel));
    channels.at(channel).addUser(user);
    result = "Successfully created channel '"+channel+"'";
  }
  return result;
}

std::string IRCCommandHandler::getChannels() {
  // GETCHANNELS
  std::string result;
  for (auto channel : channels) {
    result += channel.first+' ';
  }
  return result;
}

std::string IRCCommandHandler::joinChannel() {
  // JOINCHANNEL channelName userName
  std::string channelName = arguments[0];
  std::string userName = arguments[1];
  channels.at(channelName).addUser(userName);
  return userName+" successfully joined channel "+channelName;
}

std::string IRCCommandHandler::ping() {
  // PING
  return "";
}
