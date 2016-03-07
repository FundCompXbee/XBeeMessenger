#include "window.hpp"

Window::Window() {
  ptr = initscr();
}

Window::Window(int h, int w, int y, int x, int bprinty, int bprintx) :
  bprinty(bprinty),
  bprintx(bprintx),
  printy(bprinty),
  printx(bprintx),
  maxy(h - 4),
  maxx(w - 6)
{
  ptr = newwin(h, w, y, x);
  ::box(ptr, 0, 0);
}

Window::operator WINDOW*() {
  return ptr;
}

void Window::refresh() {
  wrefresh(ptr);
}

void Window::beginPrint(const std::string& str) {
  mvwprintw(ptr, printy, printx, "%s", str.c_str());
}

std::string Window::getInput() {
  char* str = new char[maxx];
  wgetstr(ptr, str);
  refresh();
  return std::string(str);
}

void Window::clear() {
  werase(ptr);
  box(ptr, 0, 0);
  printx = bprintx;
  printy = bprinty;
}

void Window::print(const std::string& str) {
  wmove(ptr, printy, printx);
  int count{0};
  for (char letter : str) {
    if (count >= maxx || letter == '\n') {
      ++printy;
      wmove(ptr, printy, printx);
      count = 0;
    }
    else {
      waddch(ptr, letter);
      ++count;
    }
  }
  refresh();
  ++printy;
}
