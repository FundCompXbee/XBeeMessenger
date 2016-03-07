#include <ncurses.h>
#include <string>

class UI {
public:
  UI();
  ~UI();
  void startUI();
  //std::string getInput();
  //void setInputPrompt();
  //void printOutput();
  void wait();
private:
  WINDOW* inputWin;
  WINDOW* outputWin;
};
