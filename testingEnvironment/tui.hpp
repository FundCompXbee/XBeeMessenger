#include <ncurses.h>
#include <string>
#include "window.hpp"

class TUI {
public:
  TUI();
  ~TUI();
  void start();
  void setInputPrompt(const std::string&);
  int getchar();
  void refresh();
  std::string getInput();
  void output(const std::string&);
  void display(const std::string&);
private:
  std::string prompt;
  Window stdscr;
  Window inputWin;
  Window outputWin;
  Window displayWin;
};
