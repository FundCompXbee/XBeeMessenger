#include "window.hpp"

Window::Window() {
  ptr = initscr();
}

Window::Window(int h, int w, int y, int x, int printy, int printx) :
  printy(printy),
  printx(printx),
  maxy(h - 4),
  maxx(w - 4)
{
  ptr = newwin(h, w, y, x);
}

Window::operator WINDOW*() {
  return ptr;
}

void Window::refresh() {
  wrefresh(ptr);
}

void Window::box() {
  ::box(ptr,0,0);
}

void Window::beginPrint(const std::string& str) {
  mvwprintw(ptr, printy, printx, "%s", str.c_str());
}

std::string Window::getInput() {
  char* str = new char[maxx];
  wgetstr(ptr, str);
  return std::string(str);
}

void Window::clear() {
  for (int y{1}; y <= maxy - 1; ++y) {
    for (int x{1}; x <= maxy - 1; ++x) {
      mvwaddch(ptr, y, x, ' ');
    }
  }
}

void Window::print(const std::string& str) {
  mvwprintw(ptr, printy, printx, "%s", str.c_str());
}
