#include <ncurses.h>
#include <string>

#ifndef WINDOW_H
#define WINDOW_H

class Window {
public:
  Window();
  Window(int h, int w, int y, int x, int bprinty, int bprintx);
  operator WINDOW*();
  void refresh();
  void beginPrint(const std::string&);
  std::string getInput();
  void print(const std::string&);
  void clear();
private:
  WINDOW* ptr;
  int bprinty, bprintx;
  int printy, printx;
  int maxy, maxx;
};

#endif
