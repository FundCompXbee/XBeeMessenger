#include <ncurses.h>
#include <json/json.h>
#include "tui.hpp"

std::vector<std::string> MessageFields {"destination", "source", "timestamp", "content"};

int main() {
  Json::Value root;
  TUI ui;
  ui.start();

  std::string input;
  ui.setInputPrompt("Enter Command: ");
  while ((input = ui.getInput()) != "q") {

    if (input == "json") {
      ui.setInputPrompt("Enter JSON Object Type: ");
      if ((input = ui.getInput()) == "message") {
        for (std::string field : MessageFields) {
          ui.setInputPrompt("Enter \""+field+"\": ");
          root[field] = ui.getInput();
          ui.display(root.toStyledString());
        }
      }
    }

    ui.setInputPrompt("Enter Command: ");
    ui.display(root.toStyledString());
  }
  return 0;
}
