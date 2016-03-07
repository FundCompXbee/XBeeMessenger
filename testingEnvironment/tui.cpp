#include "tui.hpp"

TUI::TUI() :
  stdscr(),
  inputWin(5, COLS, LINES - 5, 0, 5 / 2, 2),
  outputWin(LINES - 5, COLS / 2, 0, COLS / 2, 2, 3),
  displayWin(LINES - 5, COLS / 2, 0, 0, 2, 3)
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
  inputWin.refresh();
}

int TUI::getchar() {
  return getch();
}

void TUI::refresh() {
  displayWin.refresh();
  outputWin.refresh();
  inputWin.refresh();
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

void TUI::display(const std::string& str) {
  displayWin.clear();
  displayWin.print(str);
  refresh();
}
