#include <ncurses.h>
#include <string>

class Window {
public:
  Window();
  Window(int h, int w, int y, int x, int printy, int printx);
  operator WINDOW*();
  void refresh();
  void beginPrint(const std::string&);
  std::string getInput();
  void print(const std::string&);
  void clear();
private:
  WINDOW* ptr;
  int printy, printx;
  int maxy, maxx;
};
