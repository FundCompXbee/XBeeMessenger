#include "tui.hpp"

TUI::TUI() :
  stdscr(),
  inputWin(5, COLS, LINES - 5, 0, 5 / 2, 2),
  outputWin(LINES - 5, COLS, 0, 0, 2, 3)
{
  keypad(stdscr, TRUE);
  leaveok(stdscr, true);
}

TUI::~TUI() {
  endwin();
}

void TUI::start() {
  refresh();
}

void TUI::setInputPrompt(const std::string& p) {
  prompt = p;
  inputWin.clear();
  inputWin.beginPrint(prompt);
  //  refresh();
  inputWin.refresh();
}

int TUI::getchar() {
  return getch();
}

void TUI::refresh() {
  //  ::refresh();
  inputWin.refresh();
  outputWin.refresh();
  //  ::refresh();
}

std::string TUI::getInput() {
  std::string str = inputWin.getInput();
  inputWin.clear();
  setInputPrompt(prompt);
  refresh();
  return str;
}

void TUI::output(const std::string& str) {
  outputWin.print(str);
  refresh();
}
