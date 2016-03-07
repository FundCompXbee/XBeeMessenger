#include "tui.hpp"

TUI::TUI() :
  stdscr(),
  inputWin(5, COLS, LINES - 5, 0, 5 / 2, 2),
  outputWin(LINES - 5, COLS, 0, 0, 2, 3)
{
  keypad(stdscr, TRUE);

  inputWin.box();
  outputWin.box();
}

TUI::~TUI() {
  endwin();
}

void TUI::start() {
  refresh();
}

void TUI::setInputPrompt(const std::string& prompt) {
  inputWin.clear();
  inputWin.beginPrint(prompt);
  refresh();
}

int TUI::getchar() {
  return getch();
}

void TUI::refresh() {
  ::refresh();
  inputWin.refresh();
  outputWin.refresh();
  ::refresh();
}

std::string TUI::getInput() {
  return inputWin.getInput();
}

void TUI::output(const std::string& str) {
  outputWin.print(str);
  refresh();
}
