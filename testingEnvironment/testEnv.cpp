#include <ncurses.h>
#include "/usr/include/jsoncpp/json/json.h"
#include "tui.hpp"

int main()
{
  TUI ui;
  ui.start();
  std::string input;
  ui.setInputPrompt("Enter Message: ");

  // Sample JSON to test functionality
  Json::Value fromS;
  Json::Value array;
  array.append("hello");
  array.append("world");
  fromS["hello"] = "world";
  fromS["number"] = 2;
  fromS["array"] = array;
  fromS["object"]["hello"] = "world";
 
  while ((input = ui.getInput()) != "FUCK") {
    ui.output(input);
    if (input == "JSON" && input != "END") {
	std::cout << "\nNice Format\n";
	Json::StyledWriter styledWriter;
	std::cout << styledWriter.write(fromS);
	std::cout << "\nAfter Parsing\n" ;
	Json::FastWriter fastWriter;
	std::string jsonMessage = fastWriter.write(fromS);
	std::cout << jsonMessage << std::endl;
	Json::Value parsedFromString;
	Json::Reader reader;
	bool parsingSuccessful = reader.parse(jsonMessage, parsedFromString);
	if (parsingSuccessful) {
	   std::cout << styledWriter.write(parsedFromString) << std::endl;
	}
    }
  }
  return 0;
}
