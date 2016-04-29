#include "IRCCommandHandler.hpp"
#ifdef LOG1
#include "../loggerTesting/log1.h"
#else
#include "../loggerTesting/log.h"
#endif

/*
	IRCCommandHandler Class is in charge of synchronizing all of the 
	  communication and data hadling amongst the different clients in 
	  the network. This class, makes use of the user.hpp and channel.hpp
	  class. The class is included in the server.hpp class, and contains
	  the functionality necessary for acting on the different actions 
	  (commands) requested by the user. 
*/


// constructor
IRCCommandHandler::IRCCommandHandler() {
  FILELog::ReportingLevel() = FILELog::FromString(/*argv[1] ? argv[1] : */"DEBUG1"); // initializing logger
  FILE_LOG(logDEBUG) << "Initializing IRCCommandHandler logger." ;
}

// Overloading () operator. The function takes in an EXPRESSION 
//   as parameter and then calls the function associated this the 
//   COMMAND specified by the EXPRESSION. The function returns
//   the output of calling those functions, which usually is an informative 
//   message about the status of performing the specific action.
//   Expressions are strings, and need to be parsed in order to retrieve
//   the COMMAND to be excuted. 
std::string IRCCommandHandler::operator()(std::string exp) {
  expression = exp;
  if (!validExpression()) { 	// Checking if the expression is valid
    return "Invalid IRC Expresssion: "+expression;
  }
  parse();		//	Parsing function that gets the command from the EXPRESSION
  FILE_LOG(logDEBUG) << "Command = " << command;
  FILE_LOG(logDEBUG) << "Attempting to run COMMAND...";
  std::string result;
  // Calling functions associated with an EXPRESSION's COMMAND 
  if (command == "MSG") result = message();
  else if (command == "CONNECT") result = connect();
  else if (command == "CONNECT") result = disconnect();
  else if (command == "CREATECHANNEL") result = createChannel();
  else if (command == "GETCHANNELS") result = getChannels();
  else if (command == "JOINCHANNEL") result = joinChannel();
  else if (command == "PING") result = ping();
  else if (command == "CHANGENAME") result = changeName();
  else result = "Invalid IRC Command '" + command + "'";

  return result;
}

// Checks wheter an expressionhas the appropriate format, os that the parse()
//   function can accuratelly define the command varaible to the 
//   COMMAND contained inside an EXPRESION
bool IRCCommandHandler::validExpression() {
  FILE_LOG(logDEBUG) << "Expression is valid.";
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
  FILE_LOG(logDEBUG) << "Testing server requests.";
    // Try Connect Request if user not found
    if (!users.count(sender)) {
	  FILE_LOG(logDEBUG) << "Testing connect request.";
      std::string c(exp.substr(0,7));
      if (c != "CONNECT" && c != "PING") {
		FILE_LOG(logDEBUG) << "Testing expressiong for CONNECT.";
        return "Error: Sender '" + sender + "' not found OR Invalid 'CONNECT' request";
      }
	  FILE_LOG(logDEBUG) << "Valid CONNECT request confirmed!";
    }
	FILE_LOG(logDEBUG) << "Valid Server Request confiremd!";
    return "server";
  }
  // A channel request
  else {
   FILE_LOG(logDEBUG) << "Testing channel request.";
    // An invalid channel request
    if (!channels.count(dest)) {
      return "Error: Invalid Destination '" + dest + "' does not exist";
    }
    // A valid channel request
    else {
      FILE_LOG(logDEBUG) << "Valid Channel request confirmed.";
      FILE_LOG(logDEBUG) << "Testing Channel permissions.";
      // Channel permissions error
      if (!channels.at(dest).hasUser(sender)) {
        return "Error: User '" + sender + "' does not belong to channel '" + dest + "'";
      }
      FILE_LOG(logDEBUG) << "Valid channel permissions confirmed!";
    }
    FILE_LOG(logDEBUG) << "Valid channel request confirmed!";
    return "channel";
  }

  // Valid request
  FILE_LOG(logDEBUG) << "Valid request confirmed.";
  return "";
}

// Takes in the what is stored in the expression data member and tries
//   to set the command data member to that contained inside an expresssion. 
//   It also sets the value of the private data member arguments, which is 
//   a vector, to all of the words in the expression. By doing so, other functions
//   are able to access other informatino included in an expression as userName, and 
//   network
void IRCCommandHandler::parse() {
  FILE_LOG(logDEBUG) << "Beginning parse...";
  FILE_LOG(logDEBUG) << "Beginning split...";
  boost::split(arguments, expression, boost::is_any_of(" ")); // splits the string on an empty spae
  FILE_LOG(logDEBUG) << "Splitting Done.";
  command = arguments.front(); // defining the comand 
  FILE_LOG(logDEBUG) << "Command Parsing Done.";
  arguments.erase(arguments.begin());  // cleaning the arguments variable, getting ready for the next incoming command
  FILE_LOG(logDEBUG) << "Arguments Parsing Done";
  FILE_LOG(logDEBUG) << "Parsing Done.";
}

// returns the messegae content of an expression
std::string IRCCommandHandler::message() {
  // MSG message contents here
  return expression.substr(4);
}

// returns the a status message regarding the successful or unsuccessful 
//   addition of a user to the map (dictionary) of users  
std::string IRCCommandHandler::connect() {
  // CONNECT username
  std::string user{arguments[0]};

  std::string result;
  if (users.count(user) || user == "server") {
    result = "Error: User '"+user+"' already exists on the server";
  }
  else {
    users.emplace(user, User(user)); // adding key value pair of userName and userObject to the users map
    result = "Successfully connected "+user;
  }
  return result;
}

// returns a status message regarding the successful or unsuccesful
//   disconection, removal, of a user
std::string IRCCommandHandler::disconnect() {
  // DISCONNECT servername username
  std::string serverName {arguments[0]};
  std::string userName   {arguments[1]};

  if (users.count(userName) == 0) { // check whether the user actally exists in the network
    return "Disconnect Failure: User '"+userName+"' does not exist on this server";
  }

  users.erase(userName);
  for (auto& pair : channels) {
    if (pair.second.hasUser(userName)) {
      pair.second.removeUser(userName); // removing user from map
    }
  }
  return "Disconnect Success: User '"+userName+"' has been removed";
}

// returns a status message regarding the successful or unsuccesful
//    creation of a channel
std::string IRCCommandHandler::createChannel() {
  // CREATECHANNEL channelname username
  std::string channel {arguments[0]};
  std::string user    {arguments[1]};

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

// returns the list of available channels in the network
std::string IRCCommandHandler::getChannels() {
  // GETCHANNELS
  std::string result;
  for (auto channel : channels) {
    result += channel.first+' ';
  }
  return result;
}

// returns a status message regarding the successful or unsuccesful
//    joining of a user to a specific channel
std::string IRCCommandHandler::joinChannel() {
  // JOINCHANNEL channelName userName
  std::string channelName {arguments[0]};
  std::string userName    {arguments[1]};
  channels.at(channelName).addUser(userName);
  return userName+" successfully joined channel "+channelName;
}

std::string IRCCommandHandler::ping() {
  // PING
  return "";
}

// returns a status message regarding the successful or unsuccesful
//    changing of a user's name
std::string IRCCommandHandler::changeName() {
  // CHANGENAME NewName OldName
  std::string newName {arguments[0]};
  std::string oldName {arguments[1]};
  // find invalid usernames
  if (newName == "server"     ||
      users.count(newName)    ||
      channels.count(newName)
      ) {
    return "Change Name Failure: Invalid or In Use Username '"+newName+"'";
  }

  users[newName] = users[oldName];
  users[newName].setName(newName);

  users.erase(oldName);

  for (auto& pair : channels) {
    if (pair.second.hasUser(oldName)) {
      pair.second.addUser(newName);
      pair.second.removeUser(oldName);
    }
  }

  return "Change Name Success: Changed '"+oldName+"' to '"+newName+"'";
}
