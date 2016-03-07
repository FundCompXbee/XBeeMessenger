#include <ncurses.h>
#include <string>
#include "window.hpp"

class TUI {
public:
  TUI();
  ~TUI();
  void start();
  //std::string getInput();
  void setInputPrompt(const std::string&);
  //void printOutput();
  int getchar();
  void refresh();
  std::string getInput();
  void output(const std::string&);
private:
  Window stdscr;
  Window inputWin;
  Window outputWin;
};
