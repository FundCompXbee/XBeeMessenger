#include <ncurses.h>
#include <json/json.h>
#include "tui.hpp"

int main()
{
  TUI ui;
  ui.start();
  std::string input;
  ui.setInputPrompt("Enter Message: ");
  while ((input = ui.getInput()) != "FUCK") {
    ui.output(input);
  }
  return 0;
}
