#include <ncurses.h>
#include <json/json.h>
#include "tui.hpp"

int main()
{
  TUI ui;
  ui.start();
  std::string input;
  while (ui.getchar() != KEY_F(1)) {
  ui.setInputPrompt("Enter Message: ");

  ui.output(input);
  }
  // initscr();
  // keypad(stdscr, TRUE);
  // refresh();
  // WINDOW* inputWin = newwin(5, COLS, LINES - 5, 0);
  // box(inputWin,0,0);
  // mvwprintw(inputWin, getmaxy(inputWin)/2, 2, "%s", "Enter string: ");
  // wrefresh(inputWin);
  // WINDOW* outputWin = newwin(LINES - 5, COLS, 0, 0);
  // box(outputWin,0,0);
  // wrefresh(outputWin);
  // refresh();
  // char arr[80];
  // wgetstr(inputWin, arr);
  // move(LINES/2, COLS/2);
  // printw("%s",arr);
  // wclear(inputWin);
  // refresh();
  // wrefresh(inputWin);
  // while(getch() != KEY_F(1));
  // endwin();
  return 0;
}
